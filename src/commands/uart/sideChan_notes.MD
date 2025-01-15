# Trying to do side channel scanning with Bus Pirate 5
tl;dr - it isn't going to work with this target (an ARM V8 running at a decent clock speed).
## Theory
In this case, the target is in the bootloader (Das U-Boot), and is prompting for a password over the serial UART channel.  The password code is poorly written and will allow unlimited attempts with no time delay penalties.

I know from reverse engineering the code in question that the password routine is simply using `strcmp()` to check the password.  From that, we should be able to gather some side channel information based on the time it takes for the target to come back after every password attempt.  `strcmp()` is not a constant-time function - it will return as soon as it gets a non-matching character.  The longer the time it takes, the more correctly matching characters (in correct order) we have sent.

The code can try different combinations of characters and measure the time.  Any time the time goes up, we must've hit the correct "next" character.  Even better, try each combination several times and average the time!

That's the theory, anyway.
## Practice
A PIO state machine was written to watch both the UART TX and RX lines from the BP.  One of the scratch registers is loaded with 0xffffffff.  After the end of the trigger character is sent on the TX line the PIO SM will start decrementing that counter until the first falling edge is seen on the RX line.

The SM is running with no clock divider, so should be fast as possible:
```  
.program uart_sidechan

.wrap_target
    pull                    ; get max count value
    mov x OSR               ; store it in X
    pull                    ; get the number of edges in the trigger character
    mov y OSR               ; store it in Y

return_loop:
    wait 0 pin 0            ; idle state of TX line is high, wait for it to go low
    wait 1 pin 0            ; wait for it to go back up
    jmp y-- return_loop     ; decrement

timer_loop:
    jmp pin count           ; if the RX pin is still high, go decrement the counter
    jmp done                ; RX pin is low, done timing

count:
    jmp x-- timer_loop      ; decrement the counter
                            ; if it hits zero, we're also done... :/
done:
    mov isr x               ; save the timer value
    push                    ; send it back to caller program

.wrap
```  
Sure, this could be optimized, but it was the first pass.  I wanted the `pull` instructions there to control timing instead of enabling/disabling the SM.  

To test, instead of building different passwords, I just hardcoded 5 variations to try.  The known actual password is `HI2105CHIP`.  The variations should've resulted in increasingly long times based on that password.  

## Results
There really wasn't a significant difference in times.  That's telling me the PIO isn't counting fast enough.  I'd need to:
+ Optimize the PIO SM
+ Use a faster clock speed/PICO chip
+ Try against a target with a slower clock speed
+ Just break out the ChipWhisperer and do proper differential power analysis (sigh, wanted to try this with more affordable and easily usable tools)

Output from the code:  
```  
UART side channel scanning.  Press Bus Pirate button to exit.
Sending >A< iteration 1 count = 505
Sending >A< iteration 2 count = 521
Sending >A< iteration 3 count = 501
Sending >A< iteration 4 count = 516
Sending >A< iteration 5 count = 495
-->Average: 507.6

Sending >AA< iteration 1 count = 504
Sending >AA< iteration 2 count = 508
Sending >AA< iteration 3 count = 518
Sending >AA< iteration 4 count = 491
Sending >AA< iteration 5 count = 501
-->Average: 504.4

Sending >H< iteration 1 count = 511
Sending >H< iteration 2 count = 494
Sending >H< iteration 3 count = 509
Sending >H< iteration 4 count = 489
Sending >H< iteration 5 count = 503
-->Average: 501.2

Sending >HA< iteration 1 count = 481
Sending >HA< iteration 2 count = 489
Sending >HA< iteration 3 count = 498
Sending >HA< iteration 4 count = 508
Sending >HA< iteration 5 count = 515
-->Average: 498.2

Sending >HI< iteration 1 count = 490
Sending >HI< iteration 2 count = 499
Sending >HI< iteration 3 count = 506
Sending >HI< iteration 4 count = 516
Sending >HI< iteration 5 count = 492
-->Average: 500.6

Sending >HIC< iteration 1 count = 491
Sending >HIC< iteration 2 count = 493
Sending >HIC< iteration 3 count = 496
Sending >HIC< iteration 4 count = 501
Sending >HIC< iteration 5 count = 502
-->Average: 496.6

Sending >HI2015CHILLL< iteration 1 count = 502
Sending >HI2015CHILLL< iteration 2 count = 488
Sending >HI2015CHILLL< iteration 3 count = 506
Sending >HI2015CHILLL< iteration 4 count = 491
Sending >HI2015CHILLL< iteration 5 count = 508
-->Average: 499.0  
```  

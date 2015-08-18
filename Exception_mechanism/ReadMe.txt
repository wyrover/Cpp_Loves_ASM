# Exception mechanism

Because of the preceding experiment done under the Bochs Simulator,
we know that the CPU Interrupt/Exeption, for instance, #DE(Divide Error Exception), no matter when is triggered, 

always results in the corresponding instruction's being restarted.




Now turn to the another page, let's investigate the inplementation of Exception mechanism inside C++.



During the debug-time, I found it hard to track due to access violation detected by debugger.


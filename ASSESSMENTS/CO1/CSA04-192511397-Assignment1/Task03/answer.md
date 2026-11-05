# Task 3 – Operating-System Structures

| Structure | Advantages | Disadvantages | Hospital assessment |
|---|---|---|---|
| Monolithic | Fast internal service calls; simple path | Large trusted kernel; driver fault can crash system | Possible for high-performance server, but less isolation |
| Layered | Clear interfaces and modular reasoning | Layer crossings can add overhead; rigid boundaries | Useful for maintainable services |
| Microkernel | Small kernel; drivers/services isolated in user space | IPC/message-passing overhead | Strong fit for safety-oriented bedside monitors |
| Modular kernel | Loadable drivers and features; flexible | Module bugs still execute with kernel privilege | Common practical choice for Linux servers |
| Hybrid | Combines microkernel ideas and performance-oriented kernel services | Complex architecture | Suitable where platform requires it |

For bedside monitors, choose a small microkernel RTOS such as a QNX-style design or a carefully validated RTOS architecture. Keeping drivers and services isolated can prevent one faulty component from taking down the alarm scheduler. The additional message-passing cost must be measured against the 10 ms deadline.

For the database server, a modular Linux-style kernel is a practical choice: mature storage/network drivers, performance, monitoring and security tooling. Kernel modules still require controlled updates and testing.

Linux is generally monolithic with loadable modules; Windows is commonly described as hybrid; Android uses the Linux kernel with an application framework and HAL; QNX is microkernel-based.

## Alternative: monolithic monitor kernel
A monolithic kernel may reduce service communication overhead because services can call kernel routines directly. A microkernel often uses IPC between separate components, adding message-copy/context-switch costs. However, a faulty in-kernel driver can corrupt kernel memory and stop the whole monitor. For patient-safety equipment, fault containment and certification/validation outweigh a small unmeasured speed advantage. Both designs need target-hardware latency tests.

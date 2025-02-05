### **Philosophers Project 🧠🍝**  
*I never thought philosophy could be so deadly*

This project introduces developers to **threading and mutexes** in C, inspired by the classic *Dining Philosophers Problem*. The objective is to simulate philosophers who need to think, sleep, and eat spaghetti without starving, while safely coordinating the use of shared forks.

---

### 📝 **Main Instructions**  
- Philosophers must take two forks to eat (one on the right and one on the left).  
- They can only perform one action at a time: **eating**, **thinking**, or **sleeping**.  
- The simulation ends if a philosopher dies from starvation.  

---

### ⚙️ **Technical Features**  
- Global variables are prohibited.  
- Uses threads (`pthread_create`) and mutexes (`pthread_mutex`).  
- Fork states are protected by a mutex for each fork.  
- The program must log actions in real-time (in milliseconds) with specific formats such as:  
  ```plaintext
  timestamp_in_ms X has taken a fork  
  timestamp_in_ms X is eating  
  ```  
- Strict rules for memory management and coding standards compliance.  

---

### 🚀 **Authorized Functions**  
- `memset`, `printf`, `malloc`, `free`, `pthread_*`, among others.  

---

This challenge emphasizes the importance of synchronization and avoiding race conditions when programming concurrent systems. Remember: philosophers must never die! 

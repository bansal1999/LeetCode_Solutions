### **1. Approach:**
​
Used Reversed inorder Traversal (Root Right Left)
​
Used a SET to store the level and whenever a new level is found it is inserted into the set with its value in ans. Vector. At the end Ans vector is returned.
​
### **2. Approach:**
Use only vector and check the size of vector at each stage with level, if the size of vector is equal to level then insert the value in vector else that level is already visited.
Return the ans vector with node values.
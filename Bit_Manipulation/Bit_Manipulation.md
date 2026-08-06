# Bit Manipulation

## Bitwise AND (&)

think of AND as an intersection  or a filter. It require strict agreement.

## Bitwise OR (|)

Think of OR as a union or an accumulator. It preserves every 1 it sees.

## Bitwise XOR (^)

Think about it:

1. The difference detector: It flags exactly where two numbers disagree.
2. Addition without Carry

## Bitwise NOT (~)

## Left shift(<<)

If you want to create a bitmask by shifting 1 to the 40th position write 1<<40.

## Right shift (>>)

---

## The Mask ( 1 << i )

Creates a mask with only the **i-th bit set**.

```jsx
1 << 3 = 00001000
```

## Checking if a number is a power of 2

```jsx
(x > 0) && ((x & (x - 1)) == 0)
```

## Popcount (Counting Set Bits)

```jsx
__builtin_popcount(x);      // int
__builtin_popcountll(x);    // long long
```

Counts the number of `1`s in binary.

```jsx
int cnt = 0;
while (n) {
    n &= (n - 1);
    cnt++;
}     // O(logN)
```

## Isolating the lowest Set Bit

```jsx
x & (-x)
```

- Isolates the **rightmost set bit**.
- Used in **Fenwick Tree (BIT)**.

## Toggling the i-th bit

```jsx
x ^= (1 << i);
```

Flips the i-th bit.

## Clearing the i-th bit

```jsx
x &= ~(1 << i);
```

Forces the i-th bit to **0**.

## Setting the i-th bit

```jsx
x |= (1 << i);
```

Forces the i-th bit to **1**.

## Checking the i-th bit

```jsx
(x & (1 << i)) != 0
```

- `true` → bit is **1**
- `false` → bit is **0**

---

# Bitmasking:

N is hovering around 15 to 22.

Bitmasking generate all possible subsets using the bits of an integer.

#### Generating All Subsets;

```jsx
int n = 3;

// Total subsets = 2^n. We use 1 << n to quickly calculate this.
int total_subsets = 1 << n;

for (int mask = 0; mask < total_subsets; mask++) {

    // We are now looking at one specific subset (represented by 'mask')

    // Let's decode the mask to see which items are in this subset
    for (int i = 0; i < n; i++) {

        if ((mask & (1 << i)) != 0) {

            // The i-th bit is 1, so the i-th item is in this subset!
            // Process the item here...
        }
    }
}
```

### **Set Theory Operations via O(1) Bitwise Logic**

Once your sets are represented as integers, standard set operations become single CPU instructions.
Let A and B be two bitmasks representing two different subsets.

- Intersection (A ∩ B): A & B
(Items present in BOTH sets. AND only keeps bits that are 1 in both.)
- Union (A ∪ B): A | B
(Items present in AT LEAST ONE set. OR keeps a bit if it's 1 in either.)
- Symmetric Difference (A △ B): A ^ B
(Items present in exactly one set, but not both. XOR acts as a toggle.)
- Set Difference (A \ B): A & ~B
(Items in A but strictly NOT in B. We invert B to destroy matching bits.)
- Subset Check (A ⊆ B): (A & B) == A OR (A | B) == B
(If A is a subset of B, intersecting them should just yield A).

---

### Submask Enumeration

generating all subsets of a specific mask (let’s say 10110).

```jsx
int mask = 22; // Binary 10110

// We start with the submask equal to the mask itself
for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
    // Process the valid submask here
}

// Note: If you also need to process the empty set (0),
// you can do it outside the loop, as this loop terminates when submask 
// reaches 0.
```

---

# Mathematical Properties:

1. XOR Algebra (The Magic Operator)

XOR (^) behaves like a highly symmetrical, reversible version of addition.
Memorize these properties, as they are the key to simplifying complex CP equations.

- Self-Inverse (Nilpotency): x ^ x = 0
    
    (Any number XORed with itself obliterates itself.
    This is used constantly to find "the single non-repeating element" in an array.)
    
- Identity Element: x ^ 0 = x
    
    (XORing with zero does nothing.)
    
- Commutativity & Associativity:
a ^ b = b ^ a
and
(a ^ b) ^ c = a ^ (b ^ c)
    
    (Order absolutely does not matter. You can rearrange an XOR sum however you want.)
    
- The Reversibility Rule:
If a ^ b = c, then you instantly know that
a ^ c = b
and
b ^ c = a.
    
    (If you have two pieces of the triangle, you can always find the third.
    This is heavily used in finding missing elements or reversing operations.)
    

## 4. Prefix XOR for Range Queries

- Build Prefix XOR:
    
    ```cpp
    P[i] = P[i-1] ^ A[i]
    ```
    
- Range XOR:
    
    ```cpp
    XOR(L, R) = P[R] ^ P[L-1]
    ```
    
    (If `L == 0`, answer is `P[R]`.)
    
- Works because **`x ^ x = 0`**, so common prefix elements cancel out.
- **Complexity:** Preprocessing **O(n)**, each query **O(1)**.

---

## 5. MSB (Most Significant Bit) Greedy Property

- In bitwise optimization (especially **XOR** and **OR**), always prioritize the **highest bit**.
- A higher bit is more valuable than all lower bits combined.
- Build the answer **from MSB → LSB**.
- **Rule:** Never sacrifice a higher bit to gain lower bits.
- Commonly used in **Maximum XOR**, **Binary Trie**, and **bitwise greedy** problems.
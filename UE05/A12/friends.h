typedef struct {
    unsigned int a;
    unsigned int b;
} friend_t;

/*
    If the sum of dividers of the number 'a' equals the number 'b',
        and the sum of dividers of the number 'b' equals the number 'a',
        than a and b are friends.
    The function receives a friend_t pointer 'friends' to an array.
    It appends every pair of friends found to this array, linked by an friend_t struct.
    The remaining space in the array is communicated to the function by the variable 'size'.
    Furthermore, the function receives a uint-array to store values for computation.
    The maximal number is 'max' to be tested to be a friend.
    The functions sums up all 'friendly' numbers and returns this value.
*/
unsigned int sumFriends(friend_t friends[], unsigned int size, unsigned int* buffer, unsigned int max);
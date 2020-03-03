//1. Iterate through all combinations of an array
int range = 1<<n;
for(int i=0;i<range;i++)
{
    int x=i, index=0;
    while(x>0)
    {
        if(x&1)         //check last bit
        {
            //last bit is 1 -> use value at index
        }
        else
        {
            //last bit is 0 -> dont use value at index
        }
        index++;
        x>>=1;
    }
}



//2. Check odd even faster:
//Check last bit using & bitwise operator
if(x&1)
    //odd
else
    //even



//3. Multiply or divide by 2^n:
x = x<<n;   //multiply by 2^n
x = x>>n;   //divide by 2^n



//4. Set or unset a bit at nth position:
x = x | (1 << (n-1)); //set nth bit
x = x & ~(1 << (n-1)); //unset nth bit
x = x ^ (1 << (n-1)); //toggle nth bit



//5. Swap two numbers:
a ^= b;
b ^= a;
a ^= b;

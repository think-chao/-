void MySwap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
 
void Shuffle(int n)
{
    for(int i=n-1; i>=1; i--)
    {
        MySwap(num[i], num[rand()%(i+1)]);
    }
}

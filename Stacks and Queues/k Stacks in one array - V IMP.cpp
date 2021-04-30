/*
GeeksforGeeks - K stacks in a single array
space optimization max
*/

class kStacks
{
	int *arr; 
	int *top; 
	int *next;
	int n, k;
	int free; 
	
public:

	kStacks(int k, int n);

	bool isFull() { return (free == n); }

	void push(int item, int sn);

	int pop(int sn);

	bool isEmpty(int sn) { return (top[sn] == -1); }
};

kStacks::kStacks(int k1, int n1)
{
	
	k = k1, n = n1;
	arr = new int[n];
	top = new int[k];
	next = new int[n];

	for (int i = 0; i < k; i++)
		top[i] = -1;

	free = 0;
	for (int i=0; i<n; i++)
		next[i] = i+1;
}


void kStacks::push(int item, int sn)
{
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    
    int addidx = free;
    free = next[addidx];
    arr[addidx] = item;
    next[addidx] = top[sn];
    top[sn] = addidx;
	
}

int kStacks::pop(int sn)
{
    if(isEmpty(sn)){
        cout<<"Stack Empty"<<endl;
        return -1;
    }
    
    int remidx = top[sn];
    int ans = arr[remidx];
    top[sn] = next[remidx];
    next[remidx] = free;
    free=remidx;
    return ans;
	
}

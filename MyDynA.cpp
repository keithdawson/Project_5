class MyDynamicArray {
private:
	int size, limit, error, *a;
public:
	MyDynamicArray() {
		a = new int[limit = 2];
		size = error = 0;
	}
	MyDynamicArray(int s) {
		a = new int[limit = size = s];
		error = 0;
	}
	~MyDynamicArray() {
		delete a;
	}
	int& operator[](int i){
		if (i>=size || i < 0) {return error;}
		return *(a+i);
	}
	void add(int v) {
		if(size == limit) {
			int *temp = new int[limit *= 2];
			//cout << "Doubling to : " << limit << endl;
			for (int i = 0; i<size; i++)  temp[i]=a[i];
			delete a;
			a = temp;
		}
		a[size++] = v;
	}
	void del() {
		size--;
		if (size <= limit/4) {
			int *temp = new int[limit /= 2];
			//cout << "Reducing to : "<< limit << endl;
			for (int i = 0; i<size; i++)  temp[i]=a[i];
			delete a;
			a = temp;
		}
	}
	int length() { return size;}
	void clear() {
		delete a;
		a = new int[limit=2];
		size = 0;
	}
};
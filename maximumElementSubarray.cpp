vector < int > func(vector < int > &A){
  
    int n = (int)A.size();
    long long int l[n], r[n];
    vector <int > lr(n);
  
    for(int i = 0; i < n; i += 1) {
        l[i] = r[i] = 1;
    }

    for(int i = 1; i < n; i += 1) {
        int last = i-1;
        while(last >= 0 and A[i] > A[last]) {
            l[i] += l[last];
            last -= l[last];
        }
    }
   
    for(int i = n-2; i >= 0; i -= 1) {
        int last = i+1;
        while(last < n and A[i] >= A[last]) {
            r[i] += r[last];
            last += r[last];
        }
    }
 
    for(int i = 0; i < n; i += 1) {
        lr[i] = l[i] * r[i];
    }
	return lr;
	
}

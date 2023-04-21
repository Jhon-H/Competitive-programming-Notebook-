// O(n * 2^n)
void subsets(int S[], int n) { 
  int nSub = 1<<n;  
  for(int i=0; i<nSub; i++){ 
    cout<<"{ "; 
    for(int k=0; k<n; k++){ 
      //if the k-th bit is set 
      if( (1<<k) & i){ 
        cout<<S[k]<<" "; 
      }  
    } 
    cout<<"}\n"; 
  } 
} 
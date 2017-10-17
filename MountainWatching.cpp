//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int h[10050], m[10050], s=1;

int main()
{
    int n, ht=0;
    int wi, lar=0;
    int i, j;
    m[0]=0;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> h[i];
    }
    
    ht=h[0];
    for(i=1;i<n;i++){
        if(h[i]>h[i-1] || (i==0 && h[i]!=1)){
            ht=h[i];
        }
        if(h[i]<h[i-1] && ht!=0){
            m[s++]=i-1, ht=0;
        }
    }
    if(h[n-1]!=1){
        m[s++]=i-1;
    }
    
    for(i=0;i<s;i++){
        wi=0;
        for(j=m[i]+1;j<n;j++){
            if(h[j]>h[j-1]){
                break;
            }
            wi++;
        }
        for(j=m[i]-1;j>=0;j--){
            if(h[j]>h[j+1]){
                break;
            }
            wi++;
        }
        if(wi>lar){
            lar=wi;
        }
    }
    
    cout << lar+1 << endl;
    
    return 0;
}

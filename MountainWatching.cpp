/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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

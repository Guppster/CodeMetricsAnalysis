
    /* 
     * File:   newmain.cpp
     * Author: dinesh
     *
     * Created on March 8, 2009, 10:27 AM
     */
    
    #include <stdlib.h>
    #include <iostream>
    #include <vector>
    #include <algorithm>
    
    using namespace std;
    
    /*
     * 
     */
    int main(int argc, char** argv) {
      int t, i, n;
      cin >> t;
      int a[t];
      for(i = 0; i < t; i++){
        cin >> a[i];
      }
      sort(&a[0], &a[t]);
      for(i = 0; i < t; i++){
        cout << a[i] << endl;
      }
      return (EXIT_SUCCESS);
    }
    
    


      int sum =arr[0]; 
        
        int maxi =INT_MIN; 
        
        for(int i = 1; i< arr.size(); i++){
              maxi = max(maxi,sum); 
          
            sum+=arr[i]; 
         
            if(sum<0 || sum<arr[i]){
                sum = arr[i]; 
            }
        }
        maxi = max(sum,maxi); 
        return maxi; 

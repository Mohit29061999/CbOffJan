
///problem link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/



///problem link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class TrieNode{
public:
    TrieNode* child[2];

    TrieNode(){
        ///child =Null;
        for(int i=0;i<2;i++){
            child[i]=NULL;

        }
    }
};

//to insert a no in trie
void insert(TrieNode* root,int x){
    TrieNode* curr=root;


    for(int i=31;i>=0;i--){  ///insert bits of x from 31st bit to 0th
           int y=(1<<i); ///a number with ith bit 1 and rest all 0
           //cout << y << endl;
           ///check if ith bit of x is set or unset
           int z=(y&x);

          if(z>0){
              z=1;
          }
               if(curr->child[z]==NULL){
                   curr->child[z]=new TrieNode();
               }
               curr=curr->child[z];
           }






}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();

        TrieNode* root = new TrieNode();  ///create a dummy node

        for(int i=0;i<n;i++)
              insert(root,nums[i]);

        int ans =0;

        for(int i=0;i<n;i++){
            ///pick no one by 1 and see what max_xor we can


            int max_xor=0;
            TrieNode* curr = root;
            for(int j=31;j>=0;j--){
                ///find a no with different jth bit first
                //if is not then keep same jth bit
                int y=(1<<j);
                int z=(nums[i]&y);

                if(z==0){ //if jth bit of nums[i] is unset
                          ///then find number with jth bit set
                    if(curr->child[1]!=NULL){
                        ///select that no
                        max_xor+=(y);
                        curr= curr->child[1];
                    }
                    else{
                        curr=curr->child[0];
                    }

                }
                else{
                    //if jth bit of nums[i] is set
                          ///then find number with jth bit unset
                    if(curr->child[0]!=NULL){
                        ///select that no
                        max_xor+=(y);
                        curr= curr->child[0];
                    }
                    else{
                        curr=curr->child[1];
                    }
                }
            }

            ans = max(ans,max_xor);

        }
        return ans;

    }
};

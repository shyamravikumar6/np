#include<bits/stdc++.h>
using namespace std;



void computeLPSArray(char* pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{  int k=0;
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i++ < N) { 


		// mismatch after j matches 
          while(j>0 and pat[j]!=txt[i]) j=lps[j-1];


		if (pat[j] == txt[i]) { 
			j++; 
			 
		} 

		if (j == M) { 
			 k++; 
			j = lps[j - 1]; 
		} 

		
	} 
	cout<<k;
} 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	    for(;i<M; ++i){
            while(len >0 and pat[len]!=pat[i]) len=lps[len];
		   if(pat[len]==pat[i]) len++;
		   lps[i]=len;
			
		}

} 

// Driver program to test above function 
int main() 
{ 
	char txt[1000];
	char pat[1000];
     cin>>pat>>txt;

  KMPSearch(pat,txt);

} 


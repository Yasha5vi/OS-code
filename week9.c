#include<stdio.h>
#include<string.h>

int main(){
	int np;
	scanf("%d",&np);
	
	int ab[np][2];
	
	for(int i=0;i<np;i++){
		scanf("%d",&ab[i][0]);	
	}
	for(int i=0;i<np;i++){
		scanf("%d",&ab[i][1]);	
	}
	
	// sort
	for(int i=0;i<np;i++){
		for(int j=1;j<np-i;j++){
			if(ab[j-1][0] > ab[j][0]){
				int ta = ab[j-1][0];
				int tb = ab[j-1][1];
				ab[j-1][0] = ab[j][0]; 
				ab[j-1][1] = ab[j][1];
				ab[j][0] = ta;
				ab[j][1] = tb;
			}
		}
	}
	
	int sc[np][2];
	int ct = 0;
	for(int i=0;i<np;i++){
		sc[i][0] = ct;
		ct+=ab[i][1];
		sc[i][1] = ct;
	}	
	
	int wtat[np][2];
	double wt = 0,tat = 0;
	for(int i=0;i<np;i++){
		wtat[i][1] = sc[i][1] - ab[i][0];
		wtat[i][0] = wtat[i][1] - ab[i][1];
		wt+=wtat[i][0];
		tat+=wtat[i][1];
	}	
	
	printf("Pid\tA Time\tB Time\tS Time\tC Time\tW Time\tTat Time\n");
	for(int i=0;i<np;i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
		i,ab[i][0],ab[i][1],sc[i][0],sc[i][1],wtat[i][0],wtat[i][1]);
	}
  
	printf("Average waiting time : %0.2f\n",wt/np);
	printf("Average Turn around time : %0.2f\n",tat/np);
	return 0;	 
}

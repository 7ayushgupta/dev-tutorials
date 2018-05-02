#include <stdio.h>
#include <stdlib.h>

/****** DO NOT MODIFY: Begin *****/

//structure: cell
//holds the value at its location and links towards right and down directions
typedef struct node {
	int value;
	struct node *right;
	struct node *down;
} cell;
cell *array_head;

cell* getnode(int down, int right);
/****** DO NOT MODIFY: End *****/


/****** FUNCTIONS TO MODIFY: Begin *****/

//function: makenode 1/4
//Returns pointer to a new cell holding given int val in its value component
cell* makenode(int val) {
    //===========================================
	// enter your code here [5 Marks]     --- 1/4
	//===========================================
	cell *temp = (cell *)malloc(sizeof(cell));
	temp->value = val;
	temp->right = NULL;
	temp->down = NULL;
	return temp;
	//===========================================
	// your code ends here              ----- 1/4
	//===========================================
}


//function: swap 2/4
//Given two pointers to some existing cells, swap these pointers without swapping
//the contents of cells
void swap(cell **a, cell **b) {
	//===========================================
	// enter your code here [5 Marks]  ----- 2/4
	//===========================================
	cell *temp = *b;
	*a = *b;
	*b = *temp;
	//===========================================
    // your code ends here              ----- 2/4
    //===========================================
}

//function: createRightDownLinks 3/4
//Create the right and down links while taking new input elements
void createRightDownLinks(int n, int m){
    cell *corner = array_head;
	for(int i=0; i<n; i++) {
		cell *temprow = corner->down;
		cell *tempcol = corner->right;
		for(int j=0; j<m; j++) {
			int val;
			scanf("%d", &val);
			cell *temp = makenode(val);
			//===========================================
	        // enter your code here [10 Marks]  ----- 3/4
	        //===========================================
			temprow->right = temp;
			tempcol->down = temp;
			tempcol = tempcol->right;
			temprow = temp;			
			//===========================================
            // your code ends here              ----- 3/4
            //===========================================
		}
		corner = corner->down;
	}
}

//function: swapRectangle 4/4
//Swap the exclusive rectangular areas, as explained in question
void swapRectangle(int n, int m){
    int i, j, r1, c1, r2, c2, p, q;
	scanf("%d%d%d%d%d%d", &r1, &c1, &r2, &c2, &p, &q);
	cell *corner1 = getnode(r1-1, c1-1), *temp1;
	cell *corner2 = getnode(r2-1, c2-1), *temp2;
    
    //===========================================
    // enter your code here [20 Marks]  ----  4/4
    //===========================================
	
	
	//===========================================
    // your code ends here              ----- 4/4
    //===========================================
}

/****** FUNCTIONS TO MODIFY: End *****/


/****** DO NOT MODIFY: Begin *****/

//function: getnode
//Returns a pointer to pre-existing cell located at (i,j)th position in the grid
cell* getnode(int down, int right) {
	cell *temp = array_head;
	while(down>0 && right>0) {
		if(rand()%2) {
			temp = temp->right;
			right--;
		} else {
			temp = temp->down;
			down--;
		}
	}
	while(down--) temp = temp->down;
	while(right--) temp = temp->right;
	return temp;
}

//function: makeGrid
//Creating the left and top border to hold the grid
void createBorders(int n, int m) {
    cell *temp;

	temp = array_head;
	for(int i=0; i<n; i++) {
		temp->down = makenode(0);
		temp = temp->down;
	}
	temp = array_head;
	for(int j=0; j<m; j++) {
		temp->right = makenode(0);
		temp = temp->right;
	}
}

//function: printGrid
//Print the resulting grid
void printGrid(int n, int m){
    for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			printf("%d ", getnode(i,j)->value);
		}
		printf("\n");
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	array_head = makenode(0);
	
	createBorders(n, m);
	createRightDownLinks(n, m);
	
	swapRectangle(n, m);
	
	printGrid(n, m);
	return 0;
}

/****** DO NOT MODIFY: End *****/
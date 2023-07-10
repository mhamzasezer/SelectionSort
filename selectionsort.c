#include <stdio.h>
struct data {
	int key;
	double data1;
	double data2;
	double data3;
};

int read_data(char *, struct data *);
void print_data(struct data *, int);
void swap(struct data *, int, int);
int search_min(struct data *ptr, int min, int b);
void selection_sort(struct data *, int);

int main(void) {
	struct data d[1000];
	int n;

	n = read_data("data.csv", d);
	
	printf("Before\n");
	print_data(d,n);

	selection_sort(d, n);

	printf("After\n");
	print_data(d, n);

	return 0;
}

int read_data(char *ptr, struct data *rd) {
	FILE *fp;
	int i;
	fp = fopen(ptr, "r");
	if (fp == NULL) {
		printf("File Not Found.\n");
	}
	for (i = 0; i < 1000; i++) {
		if (feof(fp) != 0) {
			fclose(fp);
			return i;
		}
		fscanf(fp, "%d, %lf, %lf, %lf", &(rd + i)->key, &(rd + i)->data1, &(rd + i)->data2, &(rd + i)->data3);
	}
	printf("Too many data\n");
	return -1;
}

void print_data(struct data *ptr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Key = %d Data = %f, %f, %f\n", (ptr + i)->key, (ptr + i)->data1, (ptr + i)->data2, (ptr + i)->data3);
	}
	return;
}

void swap(struct data *ptr, int a, int b) {
	struct data tmp;
	tmp.key = ptr[b].key;
	tmp.data1 = ptr[b].data1;
	tmp.data2 = ptr[b].data2;
	tmp.data3 = ptr[b].data3;
	ptr[b].key = ptr[a].key;
	ptr[b].data1 = ptr[a].data1;
	ptr[b].data2 = ptr[a].data2;
	ptr[b].data3 = ptr[a].data3;
	ptr[a].key = tmp.key;
	ptr[a].data1 = tmp.data1;
	ptr[a].data2 = tmp.data2;
	ptr[a].data3 = tmp.data3;
}

int search_min(struct data *ptr, int min, int b) {
	int i;
	for (i = min + 1; i < b; i++) {
		if (ptr[i].key < ptr[min].key) {
			min = i;
		}
	}
	return min;
}

void selection_sort(struct data *d, int n) {
	int i;
	int min;

	for (i = 0; i < n - 1; i++) {
		min = search_min(d, i, n);
		swap(d, i, min);
	}
}
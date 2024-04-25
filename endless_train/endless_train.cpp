#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct train {
	int light;
	train* next;
	train* prev;
}train;

train* init(int light) {
	train* carriage;
	carriage = (train*)malloc(sizeof(train));

	carriage->light = light;
	carriage->next = carriage;
	carriage->prev = carriage;

	return(carriage);
}

train* addelem(train* carriage, int light) {
	train* temp_carriage, *pointer;
	temp_carriage = (train*)malloc(sizeof(train));

	pointer = carriage->next;
	carriage->next = temp_carriage;
	temp_carriage->light = light;
	temp_carriage->next = pointer;
	temp_carriage->prev = carriage;
	pointer->prev = temp_carriage;

	return(temp_carriage);
}

int main() {
	int start = clock();
	srand(time(NULL));
	int light1 = rand() % 2;

	train* carriage = init(light1);

	int carriage_count1 = 17006;
	printf("%d\n", carriage_count1);
	for (int i = 0; i < carriage_count1 - 1; i++)
	{
		int light = rand() % 2;
		addelem(carriage, light);
	}
	int carriage_count = 0;
	if (carriage->light == 0)
		carriage->light = 1;

	while (true)
	{
		carriage = carriage->next;
		carriage_count++;

		if (carriage->light == 1)
		{
			carriage->light = 0;
			for (int i = 0; i < carriage_count; i++)
				carriage = carriage->prev;
			if (carriage->light == 0)
			{
				int end = clock() - start;
				printf("Found carriges: %d\nTime - %d", carriage_count, end);
				break;
			}
			else
				carriage_count = 0;
		}
	}
}

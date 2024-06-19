#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct thread_result{
	long long result;
};
void* factorial_thread(void* arg) {
	int n = *(int*)arg;
	long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	struct thread_result* res = (struct thread_result*)malloc(sizeof(struct thread_result));
	res->result = result;

	return (void*)res;
} 

int main() {
	int num;
	printf("Enter any number: ");
	scanf("%d", &num);


	pthread_t threads[4];// CREATE 4 THREADS
	int args[4] = {num, num, num, num};
	struct thread_result* results[4];

	for (int i = 0; i < 4; i++) {
		pthread_create(&threads[i], NULL, factorial_thread, &args[i]);
	}
	for (int i = 0; i <4; i++) {
		pthread_join(threads[i], (void**)&results[i]);
	}

	for (int i = 0; i < 4; i++) {
	printf("Thread %d finished. Factorial of %d is %lld\n", i, num, results[i]->result);
	free(results[i]);
	}

	return 0;
}

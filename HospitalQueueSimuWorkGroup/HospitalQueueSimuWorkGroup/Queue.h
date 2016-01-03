float *CreateQueue()
{
	float *Q;

	Q = (float *)malloc(sizeof(float));
	if (Q == NULL)
		return NULL;
	Q[0] = -1.0;  // indicate the end of Queue
	return Q;
}


int EmptyQueue(float *Q)
{
	if (Q[0] < 0)
		return 1;   // empty
	return 0;
}

float *InsertQueue(float X, float *Q)
{
	int tam = 1;
	while (Q[tam - 1] >= 0)
		tam++;
	tam++;
	Q = (float *)realloc(Q, tam * sizeof(float));
	if (Q == NULL)
		return NULL;
	Q[tam - 2] = X;
	Q[tam - 1] = -1.0;
	return Q;
}

float *RemoveQueue(float *Q)
{
	int i, tam = 1;

	while (Q[tam - 1] >= 0)
	{
		Q[tam - 1] = Q[tam];
		tam++;
	}
	tam--;
	Q = (float *)realloc(Q, tam * sizeof(float));
	return Q;
}

float Front(float *Q)
{
	return Q[0];
}

void ShowQueue(float *Q)
{
	int k = 0;
	while (Q[k] >= 0)
	{
		printf("%f\n", Q[k]);
		k++;
	}
}


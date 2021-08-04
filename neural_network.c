#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double sigmoid(double x);
double sigmoid_dx(double x);
void set_weights(double **weights, int layers, int max_factor, int *topology);

struct neuron{
    double input;
    double output;
};

int main()
{
    srand(time(NULL));
    //топология нейронной сети *РЕДАКТИРУЕТСЯ*
    int topology[] = 
    {
    3 /*количество входных нейронов*/, 
    2, 5 /*последовательное количество нейронов на каждом скрытом слое*/,
    1 /*количество выходных нейронов*/,
    4 /*кодичество всех слоёв*/ 
    };
    //переменная, отвечающая за максимальное количество нейронов
    const int max = 0;
    int length = sizeof(topology)/sizeof(int);
    //количество слоёв выделяем в отдельную переменную
    const int layers = topology[length-1];
    for(int i = 0; i < layers ; i++)
    {
        if(max < topology[i])
        {
            int *m = (int*)&max;
            *m = topology[i];
        }
    }
    //двумерный массив, отвечающий за объединение нейронов в слои в нейронной сети
    struct neuron neurons[layers][max];
    //максимальное количество связей между двумя слоями
    const int max_factor = 0; /*Жду своих денег за рекламу, производители косметики*/
    for(int i = 1; i < length; i++)
    {
        if(topology[i - 1] * topology[i] > max_factor)
        {
            int *ptr = (int*)&max_factor;
            *ptr = topology[i-1] * topology[i];
        }
    }
    //двумерный массив, отвечающий за связи между нейронами каждых соседних слоёв
    double weights[layers][max_factor];
    set_weights(weights, layers, max_factor/*уже второе упоминание!*/, topology);
    //входные данные *РЕДАКТИРУЕТСЯ*
    double inputs[3][3] = {{1,1,0},{0,1,0},{0,0,0}};
    //выходные данные *РЕДАКТИРУЕТСЯ*
    double outputs[3] = {1,0,0};
}

double sigmoid(double x)
{
    double result = 1 / (1 + exp(-x));
    return result;
}

double sigmoid_dx(double x)
{
    double sig = sigmoid(x);
    double result = sig * (1 - sig);
    return result;
}

void set_weights(double **weights, int layers, int max_factor, int *topology)
{
    for(int i = 0; i < layers; i++)
    {
        for(int j = 0; j < max_factor; j++)
        {
            if(j < topology[i]*topology[i+1])
            {
                weights[i][j] = rand() % 4 + 1;
            }
            else
            {
                weights[i][j] = 0;
            }
        }
    }
}
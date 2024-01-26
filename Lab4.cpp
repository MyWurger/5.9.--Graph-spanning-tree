/********************************************************************************
 * Л А Б О Р А Т О Р Н А Я   Р А Б О Т А  №4  З А   5   С Е М Е С Т Р   С  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab4                                               *
 * File Name     : Lab4. CPP                                                    *
 * Programmer(s) : Викулов Д.Г.                                                 *
 * Modifyed By   :                                                              *
 * Created       : 19/09/23                                                     *
 * Last Revision : 18/10/23                                                     *
 * Comment(s)    : Программа, находящая остовное дерево графа.  Для орграфа     *
 *                 остовное дерево соотнесённого графа.                         *
 *                 Результатом является список рёбер графа, входящих в остовное *
 *                 дерево и суммарный вес дерева.                               *
 ********************************************************************************/


#include <iostream>              // стандартные потоки ввода/вывода
#include <vector>                // работа с векторами для удобства быстрого извлечения и удаления элементов
#include <chrono>                // работа со временем
#include <fstream>               // работа с потоками ввода/вывода для файла
#include <iomanip>               // библиотека с модификатором setw
#include <graphviz/gvc.h>        // библиотека Graphviz для графического изображения графа по матрице смежности
#include <opencv2/opencv.hpp>    // заголовок, подтягивающий все функции OpenCv

using namespace std;             // используем пространство имён std


/*******************************************************************/
/*            Г Л О Б А Л Ь Н Ы Е    К О Н С Т А Н Т Ы             */
/*******************************************************************/

// путь к файлу через константный указатель
// Входные файлы
// ТЕСТЫ ДЛЯ МАТРИЦЫ СМЕЖНОСТИ
//const char* FNAMEIN = "matrix_t4_001.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_002.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_003.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_004.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_005.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_006.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_007.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_008.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_009.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_010.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t4_011.txt";                // файл с матрицей смежности

// ТЕСТЫ ДЛЯ СПИСКА РЕБЕР
//const char* FNAMEIN = "list_of_edges_t4_001.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_002.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_003.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_004.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_005.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_006.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_007.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_008.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_009.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_010.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t4_011.txt";         // файл со списком рёбер

// ТЕСТЫ ДЛЯ СПИСКА СМЕЖНОСТИ
// ТЕСТОВ В АРХИВЕ НЕ ПРЕДСТАВЛЕНО


// ВЫХОДНЫЕ ФАЙЛЫ
const char* FNAMEOUT = "Output_File.txt";




/*******************************************************************/
/*      Г Л О Б А Л Ь Н Ы Е    Ф А Й Л О В Ы Е    П О Т О К И      */
/*******************************************************************/

 // объявление объекта для потокового ввода данных из файла
ifstream fin;
// объявление объекта для потокового вывода данных в файл
ofstream fout;




/*******************************************************************/
/*                 И Е Р А Р Х И Я   К Л А С С О В                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // граф в программе представлен матрицей смежности
	int m_size;                                               // размер матрицы смежности (количество вершин в графе)

public:
	// конструктор
	Graph();
	// деструктор
	~Graph();
	// константный геттер для получения значения размера
	const int GetSize();
	// функция возвращающая True, если граф ориентированный, False, если граф простой;
	bool is_directed();
	// функция, возвращающая матрицу смежности
	vector<vector<int>> adjacency_matrix();
	// весовая функция, принимает номера вершин, возвращает вес ребра, связывающего их;
	int Weight(int Vi, int Vj);
	// функция, принимающая номера вершин и возвращает True, если в графе есть соответствующее ребро / дуга, False, если ребра нет;
	bool is_edge(int Vi, int Vj);
	// функция, возвращающая список вершин, смежных вершине v;
	vector<int> adjacency_list(int v);
	// функция, возвращающая список всех рёбер графа;
	vector<pair<int, int>> list_of_edges_pairs();
	// – функция, возвращающая список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              П Р О Т О Т И П Ы    Ф У Н К Ц И Й                 */
/*******************************************************************/

// сохранение графа как фотографии
string drawGraph(const vector<vector<int>>& adjacencyMatrix);             // объявление константной ссылки на двумерный вектор adjacencyMatrix, содержащий целочисленные значения 

// вывод графа на экран в виде картинки
void OpenImage(const vector<vector<int>>& adjacencyMatrix);               // объявление константной ссылки на двумерный вектор adjacencyMatrix, содержащий целочисленные значения 

// вывод матрицы смежности на экран
void PrintMatrix(vector<vector<int>> matrix);                             // матрица, которую необходимо вывести на экран. Передача по значению

// печать справки и авторов работы
void Usloviya();

// печать условий выбора алгоритма
void Usloviya_1();

// преобразование ориентированного графа в соотнесённый ему
void convertToUndirected(vector<vector<int>>& matrix);                    // матрица смежности по ссылке для её изменения

// поиск ребра с минимальным весом
pair<int, int> getSmallestEdge(const vector<pair<int, int>> edges_pairs,  // все ребра графа, заданные в виде пар вершин, образующих их
	                           vector<vector<int>> matrix);               // матрица смежности графа

// Функция, возвращающая список всех рёбер соотнесённого графа;
vector<pair<int, int>> Symmetrical_Graph_Edges(vector<vector<int>> graph);// матрица смежности соотнесённого графа

// Алгоритм Крускалла
// работаем с корнями подмножества. Если у двух вершин - один корень подмножества i - нельзя их объединять
int find(vector<int> parent,                                              // вектор корней множеств, к которым относятся вершины
	     int vercicle);                                                   // текущая вершина

// Функция для объединения двух подмножеств
// x и y - элементы, которые мы хотим объединить в подмножество
void Union(vector<int>& parent,                                           // вектор корней множеств, к которым относятся вершины
	       int first_root,                                                // корень первого множества, которое хотим объединить
	       int second_root);                                              // корень второго множества, которое хотим объединить

// Функция для реализации алгоритма Крускала
vector<pair<int, pair<int, int>>> KruskalAlgorithm(vector<pair<int, int>>& pairs,     // вектор пар вершин соотнесённого графа 
	                                               const vector<vector<int>> graph);  // матрица смежности графа 

// Функция для реализации алгоритма прима
vector<pair<int, pair<int, int>>> primMST(vector<pair<int, int>>& pairs,              // вектор пар вершин соотнесённого графа 
	                                      const vector<vector<int>> graph);           // матрица смежности графа

// Функция для реализации алгоритма Борувки
vector<pair<int, pair<int, int>>> Boruvka(const vector<vector<int>> m_matrix);        // матрица смежности графа

// вывод матрицы  в файл
void PrintMatrToFile(vector<vector<int>> matrix);                                     // матрица, которую необходимо вывести в файл. Передача по значению




// конструктор - считывание матрицы из файла
Graph::Graph()
{
	fin.open(FNAMEIN);            // связываем объект с файлом
	if (!fin.is_open())           // файл не найден
	{
		cout << "Файла с таким именем нет. Невозможно осуществить чтение";
		fin.close();              // закрыть файл для чтения
		system("pause");
		exit(0);                  // возвращаем значение, соответствующее типу в caller
	}// if (!fin.is_open())

	int value;                    // очередной считываемый символ
	char key;                     // ключ для указания пользователем варианта задания графа в файле
	bool spravka = true;          // ключ для вывода справки на экран
	vector<int> row;              // вектор для считывания промежуточных значений из файла построчно
	vector<vector<int>> matrix;   // вспомогательная матрица смежности

	// повтор ввода задания графа, когда пользователь захотел вывести на экран справку
	while (spravka)
	{
		cout << "\x1b[30m В В Е Д И Т Е   К Л Ю Ч   И Л И   <h>   Д Л Я   В Ы З О В А   П О Д С К А З К И : \x1b[30m";
		// пользователь ввёл ключ для того, чтобы явно указать, каким способом он задал граф
		cin >> key;
		cout << "\n Вы ввели: " << key << endl;

		// в зависимости от значения ключа
		switch (key)
		{
			// работа с матрицей смежности
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   М А Т Р И Ц А   С М Е Ж Н О С Т И\n\n\x1b[30m\n";
			// считываем очередное число из файла
			while (fin >> value)
			{
				// после считывания каждой строки очищаем вектор строки
				row.clear();
				// загоняем в вектор первый считанный элемент от первого while (fin >> value)
				row.push_back(value);
				// считываем все остальные элементы строки, пока не нашли символ её окончания - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// кладем в матрицу считанную строку. Все строки имеют одинаковый размер, так как работаем с матрицей смежности
				m_matrix.push_back(row);

			}// while (fin >> value)

			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// работа со списком рёбер
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   С П И С О К   Р Ё Б Е Р\n\n\x1b[30m\n";

			// считываем значения из файла в вектор
			// в векторе будут находиться с чередованием через три элементы: начальная вершина, конечная вершина и вес ребра
			while (fin >> value)
			{
				// после считывания каждой строки очищаем вектор строки
				row.clear();
				// загоняем в вектор первый считанный элемент от первого while (fin >> value)
				row.push_back(value);
				// считываем все остальные элементы строки, пока не нашли символ её окончания - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// кладем в матрицу считанную строку. Все строки имеют одинаковый размер, так как работаем с матрицей смежности
				m_matrix.push_back(row);
			}// while (fin >> value)

			// закрыть файл чтения
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // размер матрицы смежности
			vector<vector<int>> vec_1(size_m);                // матрица смежности

			for (int i = 0; i < size_m; i++)                  // задаём размер каждой ячейки vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// заполняем матрицу смежности
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 элемент - это вес ребра, если он не указан, то значит он = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// запоминаем матрицу смежности
			m_matrix = vec_1;
			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// работаем со списками смежности
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   С П И С О К   С М Е Ж Н О С Т И\n\n\x1b[30m\n";

			// чтение из файла построчно
			string line;
			int rowNumber = 0;            // номер текущей строки

			// чтение построчное
			while (getline(fin, line))
			{
				// Если строка пустая, заполняем текущую строку нулями
				if (line.empty())
				{
					matrix.push_back(std::vector<int>(m_size, 0));
				}
				// строка не пустая
				else
				{
					// вектор строки
					vector<int> row;
					// создает поток для чтения значений из строки line. Затем мы можем использовать iss вместе с оператором >> для извлечения значений из строки.
					istringstream iss(line);
					// очередная величина для чтения
					int value;

					// читаем значение из файла и помещаем его в вектор строки
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// помещаем строку в матрицу
					matrix.push_back(row);
				}// if (line.empty()) 

				// увеличиваем номер строки
				rowNumber++;
			}// while (getline(fin, line)) 

			// файл прочитан - закрываем его
			fin.close();

			m_size = matrix.size();                         // размер матрицы смежности

			std::vector<std::vector<int>> vec_1(m_size);    // доп матрица смежности размером m_size

			for (int i = 0; i < m_size; i++)                // задаём размер каждой ячейки доп матрицы смежности
			{
				// заполняем вспомогательную матрицу нулями по всему размеру
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // заполняем доп матрицу смежности 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// единица в тех столбцах, которые перечислены для данной в файле
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// загоняем значения в основную матрицу смежности
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// пользователь выбрал справку
		case('h'):
		case('H'):
		{
			// повторить ввод после появления мправки на экране
			spravka = true;
			// выводим условия
			Usloviya();
			break;
		}

		// иначе - пользователь ввёл не тот ключ. Заканчиваем программу с ошибкой
		default:
			cout << "\n\x1b[31m ПЕРЕЗАПУСТИТЕ ПРОГРАММУ И ВВЕДИТЕ ЗНАЧЕНИЕ ИЗ СПИСКА КЛЮЧЕЙ!!!\n\x1b[30m";
			// закрываем файл считывания
			fin.close();
			exit(0);
		}
	}
	// закрываем файл считывания
	fin.close();
	// запоминаем размер считанной/ преобразованной матрицы смежности
	m_size = m_matrix.size();
}

// деструктор
Graph::~Graph()
{
	// пустое тело - векторы уничтожаются автоматически
}

// геттер для получения значения размера
const int Graph::GetSize()
{
	return(m_size);
}


// функция возвращающая True, если граф ориентированный, False, если граф простой;
bool Graph::is_directed()
{
	// идём по строкам
	for (int i = 0; i < m_size; i++)
	{
		// идём по столбцам
		for (int j = 0; j < m_size; j++)
		{
			// если граф неориентированный, то матрица симметрична, так как по ребру можно пройти подвум направлениям
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // Найдено направленное ребро - граф ориентированный
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // Не найдено направленных ребер - граф неориентированный
}


// функция, возвращающая матрицу смежности
vector<vector<int>> Graph::adjacency_matrix()
{
	// вернули матрицу смежности
	return(m_matrix);
}


// весовая функция, принимает номера вершин, возвращает вес ребра, связывающего их;
int Graph::Weight(int Vi, int Vj)

{
	// номера вершин вышли за диапазоны допустимых значений
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "Ошибка! Такой вершины не существует\n";
		// вернули ошибку
		return(-1);
	}// if

	// если путь существует(в матрице смежности не 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "Вес ребра между вершинами " << Vi << " и " << Vj << " равен" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// возвращаем вес ребра между вершинами
		return(m_matrix[Vi][Vj]);
	}// if

	// граф ориентированный. Выводим вес дуги
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "Граф ориентированный. Дуга есть. Направление учитывается. Вес дуги между вершинами " << Vi << " и " << Vj << " равен" << m_matrix[Vi][Vj] << endl;
		// возвращаем вес дуги
		return(m_matrix[Vi][Vj]);
	}// else if

	// ребра между вершинами нет - элемент матрицы смежности равен 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "Ребра между вершинами " << Vi << " и " << Vj << "нет\n";
		// Вернули нулевое значение
		return(m_matrix[Vi][Vj]);
	}// else if

	// вернули значение по-умолчанию
	return(0);
}


// функция, принимающая номера вершин и возвращает True, если в графе есть соответствующее ребро / дуга, False, если ребра нет;
bool Graph::is_edge(int Vi, int Vj)
{
	// номера вершин вышли за диапазоны допустимых значений - дуги нет
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// вернули, что дуги нет
		return(false);
	}// if

	// элемент матрицы смежности не равен 0 - ребро есть
	if (m_matrix[Vi][Vj] != 0)
	{
		// подтверждаем, что ребро есть
		return(true);
	}// if

	// элемент матрицы смежности нулевой - ребра нет
	if (m_matrix[Vi][Vj] == 0)
	{
		// подтверждаем, что ребра нет
		return(false);
	}// if

}


// функция, возвращающая список вершин, смежных вершине v;
vector<int> Graph::adjacency_list(int v)
{
	// список вершин
	vector<int> adjList;

	// Проходим по всем вершинам и проверяем, есть ли ребро между вершиной v и текущей вершиной
	for (int i = 0; i < m_size; i++)
	{
		// путь есть - элемент матрицы не нулевой
		if (m_matrix[v][i] != 0)
		{
			// помещаем вершину в список
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// Возвращаем список смежных вершин
	return adjList;
}


// функция, возвращающая список всех рёбер графа;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// вектор пар, содержащий ребро в виде двух инцидентных ему вершин
	vector<pair<int, int>> edges_pairs;
	// идём по всем элементам строки
	for (int i = 0; i < m_size; i++)
	{
		// идём по всем элементам столбца
		for (int j = 0; j < m_size; j++)
		{
			// если элемент не нулевой
			if (m_matrix[i][j] != 0)
			{
				// загрузили пару вершин
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i

	// вернули вектор рёбер (пар вершин)
	return(edges_pairs);
}


// функция, возвращающая список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // вектор пар вершин(вектор рёбер)
	vector<pair<int, int>> edges_inc;     // вектор рёбер инцидентных вершине v / исходящих из вершины v
	edges = list_of_edges_pairs();        // получаем все пары вершин графа

	// обходим эти пары. Если граф неориентированный, то там будет пара (v,n) и (n, v) - достаточно рассмотреть для инцидентности первый элемент. В орграфе - исходящий элемент всегда первый
	for (int i = 0; i < edges.size(); i++)
	{
		// рассматриваем первый элемент пары
		if (edges[i].first == v)
		{
			// помещаем в списо ребер, инцидентных вершине данное ребро
			edges_inc.push_back(edges[i]);
			// увеличиваем счётчик
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// возвращаем  список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                Функции               */
/*--------------------------------------*/

// сохранение графа как фотографии
string drawGraph(const vector<vector<int>>& adjacencyMatrix)
{
	// Проверяем размер матрицы смежности. Если больше 19, то считаем ее слишком большой
	if (adjacencyMatrix.size() <= 25)
	{
		bool key = false;
		// Проверяем наличие весов на ребрах, чтобы понять, нужно ли указывать их при выводе
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// Если вес ребра больше 1 или отрицательный, значит, нужно указывать вес в выводе
				if (adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
					key = true;
			}
		}

		// Открываем файл для записи графа в формате DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// Выводим граф с указанием весов ребер
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Проверяем, что вес ребра не равен 0, чтобы не выводить ненужные ребра
					if (adjacencyMatrix[i][j] != 0)
					{
						// Выводим ребро с указанием веса в формате DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// Выводим граф без указания весов ребер
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Проверяем, что вес ребра равен 1, чтобы не выводить ненужные ребра
					if (adjacencyMatrix[i][j] == 1)
					{
						// Выводим ребро без указания веса в формате DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// Закрываем файл и сохраняем результаты
		file << "}" << std::endl;
		file.close();

		// Генерируем изображение графа в формате PNG с помощью утилиты DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\n Graph image saved as graph.png" << endl;
	}

	// Выводим, что граф большой для рисования
	else
	{
		cout << "\n\n Graph image is not saved as graph.png. It is too big" << endl;
	}
	// возвращаем картинку для открытия силами OpenCV
	return "graph.png";
}


// вывод графа на экран
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// Проверяем размерность матрицы смежности
	if (adjacencyMatrix.size() <= 25)
	{
		// Получаем путь к изображению, созданному с помощью функции drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// Загружаем изображение с помощью OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// Проверяем, удалось ли загрузить изображение
		if (img.empty()) {
			cout << "Could not open or find the image" << endl;
			return;
		}

		// Создаем окно с названием "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// Показываем изображение в окне
		cv::imshow("Graph", img);
		// Ждем, пока пользователь нажмет любую клавишу
		cv::waitKey(0);
		// Закрываем окно
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
}


// вывод матрицы смежности на экран
void PrintMatrix(vector<vector<int>> matrix)
{
	// отключаем русский язык
	setlocale(0, "C");            // выводим массив в красивых скобках
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // вывод верхних квадратных скобок

	// идём по строкам
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// идём по столбцам
		for (int j = 0; j < matrix.size(); j++)
		{
			// выводим элемент матрицы
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // вывод верхних квадрат
	// подключаем русский язык
	setlocale(LC_ALL, "Russian");

	// возвращаем обещанное значение
	return;
}


// печать справки и авторов работы
void Usloviya()
{
	cout << "\n\t\t\t\t/********************************************************************************\n";
	cout << "\t\t\t\t* Л А Б О Р А Т О Р Н А Я   Р А Б О Т А  №4  З А   5   С Е М Е С Т Р   С  +  +  *\n";
	cout << "\t\t\t\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                     *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab4                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab4. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : Викулов Д.Г.                                                  *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                               *\n";
	cout << "\t\t\t\t* Created       : 19/09/23                                                      *\n";
	cout << "\t\t\t\t* Last Revision : 17/10/23                                                      *\n";
	cout << "\t\t\t\t********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   С П Р А В К А : \n\n\x1b[30m";
	// Выводим условия в таблице
	setlocale(0, "C");                       // отключаем русский язык
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // выводим верхнюю строку шапки
	setlocale(LC_ALL, "Rus");                // подключаем русский язык
	cout << " Выберите одно значние из списка:      ";
	setlocale(0, "C");                       // отключаем русский язык
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // выводим нижнюю строку шапки с разделителем между номером и названием алгоритма
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // выводим условия выбора и нижнюю с боковыми строчками таблицы
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // подключаем русский язык

	return;                                 // возвращаем обещанное значение
}


// печать условий выбора алгоритма
void Usloviya_1()
{
	// Выводим условия в таблице
	setlocale(0, "C");                       // отключаем русский язык
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // выводим верхнюю строку шапки
	setlocale(LC_ALL, "Rus");                // подключаем русский язык
	cout << " Выберите одно значений из списка:     ";
	setlocale(0, "C");                       // отключаем русский язык
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // выводим нижнюю строку шапки с разделителем между номером и названием алгоритма
	cout << "  k " << (char)179 << " Kruskal's algorithm              ";                                                                                                         // выводим условия выбора и нижнюю с боковыми строчками таблицы
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  p " << (char)179 << " Prim's algorithm                 ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  b " << (char)179 << " Boruvka's algorithm              ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  s " << (char)179 << " 3 algorithms alternately         ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	setlocale(LC_ALL, "Rus");               // подключаем русский язык

	return;                                 // возвращаем обещанное значение
}


// преобразование ориентированного графа в соотнесённый ему
void convertToUndirected(vector<vector<int>>& matrix)                    // матрица смежности по ссылке для её изменения
{
	// Размер матрицы смежности - количество вершин в графе
	int size = matrix.size();
	// Проходим по каждому элементу матрицы и делаем ее симметричной
	// идём по строкам
	for (int i = 0; i < size; i++)
	{
		// по столбцам, начиная с i+1-го
		for (int j = i + 1; j < size; j++)
		{
			if (matrix[i][j] != 0)
			{
				// Если есть ребро из i в j, создаем ребро из j в i
				matrix[j][i] = matrix[i][j];
			}// if (matrix[i][j] != 0) 

			else if (matrix[j][i] != 0)
			{
				// Если есть ребро из j в i, создаем ребро из i в j
				matrix[i][j] = matrix[j][i];
			}// else if (matrix[j][i] != 0) 
		}// for j
	}// for i

	// возвращаем обещанное значение
	return;
}


// поиск ребра с минимальным весом
pair<int, int> getSmallestEdge(const vector<pair<int, int>> edges_pairs,  // все ребра графа, заданные в виде пар вершин, образующих их
	                           vector<vector<int>> matrix)                // матрица смежности графа
{
	// пара вершин, образующих наименьшее ребро
	pair<int, int> smallestEdge;
	// наименьший вес ребра для сравнения и выборки минимального. Изначально он - бесконечность
	int smallestWeight = numeric_limits<int>::max();

	// идём по всем элементам вектора пар вершин
	for (int i = 0; i < edges_pairs.size(); i++)
	{
		// получаем вес текущего ребра
		int weight = matrix[edges_pairs[i].first][edges_pairs[i].second];

		// сравниваем с текущим сохранённым значением веса
		if (weight < smallestWeight)
		{
			// запоминаем вес ребра, если он меньше, чем текущий сохранённый
			smallestWeight = weight;
			// запоминаем пару вершин, формирующих ребро
			smallestEdge = edges_pairs[i];
		}// if
	}// for i

	// возвращаем пару вершин, образующих наименьшее ребро
	return smallestEdge;
}


// Функция, возвращающая список всех рёбер соотнесённого графа;
vector<pair<int, int>> Symmetrical_Graph_Edges(vector<vector<int>> graph)   // матрица смежности соотнесённого графа
{
	// вектор пар, содержащий ребро в виде двух инцидентных ему вершин
	vector<pair<int, int>> edges_pairs;
	// идём по всем элементам строки
	for (int i = 0; i < graph.size(); i++)
	{
		// идём по всем элементам столбца
		for (int j = 0; j < graph.size(); j++)
		{
			// если элемент не нулевой
			if (graph[i][j] != 0)
			{
				// загрузили пару вершин
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)

		}// for j

	}// for i
	// вернули вектор рёбер (пар вершин)
	return(edges_pairs);
}


// АЛГОРИТМ КРУСКАЛЛА
// работаем с корнями подмножества. Если у двух вершин - один корень подмножества i - нельзя их объединять
int find(vector<int> parent,                                              // вектор корней множеств, к которым относятся вершины
	     int vercicle)                                                    // текущая вершина
{
	// возвращаем индекс корня. Признак: у корня -1
	if (parent[vercicle] == -1)
	{
		return vercicle;
	}// if

	// рекурсивно вызываем функцию для прохода по всем предкам пока не дойдём до корня множества
	return find(parent, parent[vercicle]);
}


// Функция для объединения двух подмножеств
// x и y - элементы, которые мы хотим объединить в подмножество
void Union(vector<int>& parent,                                           // вектор корней множеств, к которым относятся вершины
	       int first_root,                                                // корень первого множества, которое хотим объединить
	       int second_root)                                               // корень второго множества, которое хотим объединить
{
	// обяединяем два множества - корень первого множества добавляется во второе, причем он перестаёт быть корнем. У него появляется предок
	parent[first_root] = second_root;
	// возвращаем обещанное значение
	return;
}


// Функция для реализации алгоритма Крускала
vector<pair<int, pair<int, int>>> KruskalAlgorithm(vector<pair<int, int>>& pairs,     // вектор пар вершин соотнесённого графа 
	                                               const vector<vector<int>> graph)   // матрица смежности графа 
{
	int V = graph.size(); // Количество вершин в графе

	// Создаем вектор данных, хранящихся для вершины. Изначально каждая вершина - корень своего множества
	vector<int> parent(V, -1);

	// Создаем вектор для хранения ребер минимального остовного дерева в виде (вес, (вершина1, вершина2))
	vector<pair<int, pair<int, int>>> minimumSpanningTree;

	// Проходим по всем ребрам в отсортированном порядке
	while (!pairs.empty())
	{
		// получаем очередное ребро минимального веса
		pair<int, int> smallestEdge = getSmallestEdge(pairs, graph);

		// удаляем ребро с наименьшим весом
		pairs.erase(remove(pairs.begin(), pairs.end(), smallestEdge), pairs.end());

		// получаем значения вершин, составляющих ребро минимального веса
		int first = smallestEdge.first;
		int second = smallestEdge.second;

		// находим вершины - корни множества
		int set_first = find(parent, first);
		int set_second = find(parent, second);

		// Проверяем, находятся ли корневые вершины в одном множестве
		// Если нет, то добавляем ребро в остовное дерево и объединяем множества
		if (set_first != set_second)
		{
			// добавляем ребро в результирующий вектор дерева
			minimumSpanningTree.push_back(make_pair(graph[first][second], make_pair(first, second)));
			// объединяем множества
			Union(parent, set_first, set_second);
		}// if
	}// while

	// возвращаем вектор остовного дерева
	return minimumSpanningTree;
}


// АЛГОРИТМ ПРИМА
// Функция для реализации алгоритма прима
vector<pair<int, pair<int, int>>> primMST(vector<pair<int, int>>& pairs,              // вектор пар вершин соотнесённого графа 
	                                      const vector<vector<int>> graph)            // матрица смежности графа
{
	int V = graph.size();                // Количество вершин в графе
	vector<bool> visited(V, false);      // Посещенные вершины

	// Ребра минимального остовного дерева в виде (вес, (вершина1, вершина2))
	vector<pair<int, pair<int, int>>> minimumSpanningTree;

	// стартовая вершина - первая
	int StartVertex = 0;
	// вершина помечается как добавленная в дерево
	visited[StartVertex] = true;

	// Количество рёбер в остовном дереве на единицу меньше, чем число вершин, иначе - дерево перестаёт быть остовным
	while (minimumSpanningTree.size() < V - 1)
	{
		// переменная для нахождения ребра с минимальным весом 
		int minWeight = numeric_limits<int>::max();
		// начальная вершина ребра, которое мы хотим добавить в остовное дерево
		int minSrc = -1;
		// конечная вершина ребра, которое мы хотим добавить в остовное дерево
		int minDest = -1;
		// Индекс ребра, которое нужно удалить
		int indexToRemove = -1;

		// Поиск минимального ребра, которое соединяет уже посещенные и непосещенные вершины
		for (int j = 0; j < pairs.size(); j++)
		{
			// запоминаем начало очередного ребра
			int src = pairs[j].first;
			// запоминаем конец очередного ребра
			int dest = pairs[j].second;

			// если одна вершина принадлежит дереву, а втоорая - находится за пределами дерева, и вес ребра, которое хотим добавить между этими вершинами меньше, чем сохранённый
			if ((visited[src] && !visited[dest]) && graph[src][dest] < minWeight)
			{
				// запоминаем вес этого ребра
				minWeight = graph[src][dest];
				// запоминаем начальную вершину ребра, которое хотим добавить
				minSrc = src;
				// запоминаем конечную вершину ребра, которое хотим добавить
				minDest = dest;
				// Запоминаем индекс ребра для удаления
				indexToRemove = j;
			}// if

		}// for j


		// Удаление найденного неподходящего ребра из списка ребер `pairs`
		if (indexToRemove != -1)
		{
			pairs.erase(pairs.begin() + indexToRemove);

		}// if

		// Добавление найденного ребра в минимальное остовное дерево
		minimumSpanningTree.push_back(make_pair(minWeight, make_pair(minSrc, minDest)));

		// Посещение найденной вершины
		visited[minDest] = true;
	}// while

	// возвращаем вектор остовного дерева
	return minimumSpanningTree;
}


// АЛГОРИТМ БОРУВКИ
// Функция для реализации алгоритма Борувки
vector<pair<int, pair<int, int>>> Boruvka(const vector<vector<int>> m_matrix)         // матрица смежности графа
{
	// Количество вершин в графе
	int V = m_matrix.size();               
	// Ребра минимального остовного дерева в виде (вес, (вершина1, вершина2))
	vector<pair<int, pair<int, int>>> minimumSpanningTree;
	// компонента связности
	vector <int> componenta(V);

	// Изначально каждая вершина - отдельная компонента связности. Даём уникальные номера
	for (int i = 0; i < V; i++)
	{
		componenta[i] = i;
	}// for i

	// вектор посещённых вершин
	vector<bool> visited(m_matrix.size(), false);
	// вспомогательная переменная для определения ребра минимального веса
	int min = numeric_limits<int>::max();
	// пременная для хранения номера вершины, которую мы будем добавлять к дереву
	int k;
	// флаг нахождения подходящего ребра
	bool flag = false;
	// счётчик количества рёбер
	int n = 0;

	// формирование отдельных компонент связности
	// заполнение вектора 
	// идём по всем строкам матрицы смежности
	for (int i = 0; i < V; i++)
	{
		// если вершина i не принадлежит компоненте связности
		if (!visited[i])
		{
			// заполнение вектора
			// начинаем проходить по вершинам, к которым мы можем добраться
			for (int j = 0; j < V; j++)
			{
				// поиск минимального ребра для i-й вершины
				// если ребро между вершинами существует и оно меньше, чем сохранённое min, и вершины принадлежат разным компонентам связности
				if (m_matrix[i][j] < min && m_matrix[i][j] != 0 && componenta[j] != componenta[i])
				{
					min = m_matrix[i][j];    // запомнили ребро минимального веса
					k = j;                   // запомнили номер вершины, которую будем добавлять в дерево
					flag = true;             // флаг нахождения ребра
					visited[i] = true;       // пометили начальную как посещённую
				}// if

			}// for j

		}// if

		// если нашли подходящие ребро
		if (flag)
		{
			n = n + 1;                      // увеличиваем счётчик рёбер, так как связали компоненты
			// добавляем ребро в вектор остовного дерева
			minimumSpanningTree.push_back(make_pair(min, make_pair(i, k)));
			// отмечаем добавленную вершину компоненты как посещённую
			visited[k] = true;
			// сохраняем в отдельную перменную, так как при поиске в if снизу будет неправильно работать
			int e = componenta[k];

			// поиск элементов, принадлежащих одному и тому же дереву
			for (int j = 0; j < V; j++)
			{
				// принадлежат одному дереву
				if (componenta[j] == e)
				{
					// добавляем к дереву ребро. Приравниваем номера компонент
					componenta[j] = componenta[i]; 
				}// if

			}// for j

		}// if

		// обнуляем значения для поиска следующего ребра
		flag = false;
		k = -1;
		min = numeric_limits<int>::max();
	}// for i


	vector<int> odinakov; // вектор для хранения вершин, которые принадлежат одному дереву
	int pos;              // переменная для хранения номера вершины, которую мы будем добавлять к дереву
	int vershina;         // сохраняем вершину, откуда будет начинаться ребро

	// если были добавлены не все рёбра в компонету, то проходим по отдельным деревьям. В остовном дереве V-1 ребро, т.к. по смыслу, если добавить больше, до оно перестаёт быть остовным
	if (n != V - 1)
	{
		// проход по вектору relax
		for (int i = 0; i < V; i++)
		{
			// поиск вершин, которые принадлежат одному дереву
			for (int j = 0; j < V; j++)
			{
				if (componenta[j] == componenta[i])
				{
					// добавляем номер вершины, принадлежащей данной компоненты связности
					odinakov.push_back(j);
				}// if
			}// for j

			// проход во вектору "odinakov"
			for (int j = 0; j < odinakov.size(); j++)
			{
				// поиск вершин, которые принадлежат одному дереву
				for (int k = 0; k < V; k++)
				{
					// вершины принадлежали изначально разным компонентам, но мы хотим их объединить
					if (m_matrix[odinakov[j]][k] < min && m_matrix[odinakov[j]][k] != 0 && componenta[k] != componenta[odinakov[j]])
					{
						min = m_matrix[odinakov[j]][k];
						pos = k;                     // запомнили номер вершины, которую будем добавлять в дерево
						flag = true;                 // установили флаг объединения рёбер
						vershina = odinakov[j];      // сохраняем вершину, откуда будет начинаться ребро
					}// if

				}// for k

			}// for j

			// если нашли ребро
			if (flag)
			{
				n = n + 1;                           // увеличиваем счётчик рёбер, так как связали компоненты
				// добавляем ребро в вектор остовного дерева
				minimumSpanningTree.push_back(make_pair(min, make_pair(vershina, pos)));
				int e = componenta[pos];
				// поиск элементов, принадлежащих одному и тому же дереву
				for (int w = 0; w < componenta.size(); w++)
				{
					// принадлежат одному дереву
					if (componenta[w] == e)
					{
						// добавляем к дереву ребро. Приравниваем номера компонент
						componenta[w] = componenta[i];
					}// if

				}// for w

			}// if

			// если у нас уже есть подходящее кол-во рёбер, то выходим из цикла
			if (n == V - 1)
			{
				break;
			}// if

			// обнуляем значения для поиска следующего ребра
			flag = false;
			pos = -1;
			min = numeric_limits<int>::max();
			odinakov.clear();
		}// for i

	}// if

	// возвращаем вектор остовного дерева
	return minimumSpanningTree;
}


// вывод матрицы  в файл
void PrintMatrToFile(vector<vector<int>> matrix)                 // матрица, которую необходимо вывести в файл. Передача по значению
{
	// идём по строкам матрицы
	for (int i = 0; i < matrix.size(); i++)
	{
		// идём по столбцам матрицы
		for (int j = 0; j < matrix.size(); j++)
		{
			// выводим очередной элемент матрицы в файл
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// возвращаем обещанное значение
	return;
}

/*------------------------------------------------------------------------*/
/*            Главная функция           */
/*--------------------------------------*/
int main()
{
	// подключаем русский язык
	setlocale(LC_ALL, "Russian");
	// цвет консоли - белый
	system("color F0");
	// флаг печати в файл. Изначально - печати нет
	bool print = false;
	// ключ, введённый пользователем для печати
	char letter;
	// векторы пар вершин
	// пары вершин исходного графа
	vector<pair<int, int>> pairs;
	// пары вершин соотнесённого графа
	vector<pair<int, int>> pairs_1;
	// матрица смежности графа
	vector<vector<int>> matrix;
	// вектор остовного дерева (вес(вершина1, вершина2))
	vector<pair<int, pair<int, int>>> minimumSpanningTree;


	cout << "\t\t\t\t\t\t\x1b[34m    Р А Б О Т А   С   Г Р А Ф А М И\x1b[30m\n\n\n";
	// создали объект графа. Конструктор применился по-умолчанию
	Graph NewGraph;
	
	// заполняем векторы пар
	pairs = NewGraph.list_of_edges_pairs();
	pairs_1 = NewGraph.list_of_edges_pairs();

	// получаем значение матрицы смежности
	matrix = NewGraph.adjacency_matrix();

	// Выбор, хочет ли пользователь выводить в файл вычесленную информацию
	cout << " Хотите ли Вы выводить данные в файл? Введите <o>, если хотите, или любой другой символ - если нет. Введите: ";
	cin >> letter;                             // ввод пользователем
	cout << "\n Вы ввели: " << letter;         // эхо-печать

	// Если пользователь хочет печатать. Устанавливаем флаг
	if (letter == 'o' || letter == 'O')
	{
		print = true;

		fout.open(FNAMEOUT);           // связываем объект с файлом
		if (!fout.is_open())           // файл не найден
		{
			cout << "Файла с таким именем нет. Невозможно осуществить чтение";
			fin.close();               // закрыть файл для чтения
			system("pause");
			exit(0);                   // возвращаем значение, соответствующее типу в caller
		}// if (!fout.is_open())

		fout << "\t\t\t\t\t\t    Р А Б О Т А   С   Г Р А Ф А М И\n\n\n";

	}// if (letter == 'o' || letter == 'O')

	// не будем выводить матрицу смежности для больших графов
	if (NewGraph.GetSize() <= 100)
	{
		cout << "\n\n\t\t\t\t\x1b[35m     М А Т Р И Ц А   С М Е Ж Н О С Т И   П О   И С Х О Д Н Ы М   Д А Н Н Ы М :\x1b[30m\n\n";
		PrintMatrix(NewGraph.adjacency_matrix());

		fout << "\n\n\t\t\t\t     М А Т Р И Ц А   С М Е Ж Н О С Т И   П О   И С Х О Д Н Ы М   Д А Н Н Ы М :\n\n";
		PrintMatrToFile(NewGraph.adjacency_matrix());
	}// if


	// если граф ориентированный
	if (NewGraph.is_directed())
	{
		// делаем соотнесённый ему
		convertToUndirected(matrix);
		if (NewGraph.GetSize() <= 100)
		{
			cout << "\n\n\t\t\t\t\x1b[36m      М А Т Р И Ц А   С М Е Ж Н О С Т И   С О О Т Н Е С Ё Н Н О Г О   Г Р А Ф А:\x1b[30m\n\n";
			PrintMatrix(matrix);

			fout << "\n\n\t\t\t\t      М А Т Р И Ц А   С М Е Ж Н О С Т И   С О О Т Н Е С Ё Н Н О Г О   Г Р А Ф А:\n\n";
			PrintMatrToFile(matrix);
		}// if

		// заполняем векторы пар вершин соотнесённого графа
		pairs.clear();
		pairs_1.clear();
		pairs = Symmetrical_Graph_Edges(matrix);
		pairs_1 = Symmetrical_Graph_Edges(matrix);
	}// if


	// выбор пользователья, какой алгоритм он хочет выбрать
	char key;
	cout << "\n\x1b[33m В В Е Д И Т Е   О Д И Н   И З   С Л Е Д У Ю Щ И Х   К Л Ю Ч Е Й: \x1b[30m\n";
	Usloviya_1();

	// флаг, который показывает, что были выбраны один из трёх первых алгоритмов
	bool flag = false;
	// ввод пользователем ключа алгоритма
	cout << " Ввод ключа: ";
	cin >> key;
	// эхо-печать
	cout << " Вы ввели: " << key << endl;

	// выбор алгоритма
	switch (key)
	{

	case('k'):
	case('K'):// выбрали алгоритм Крускала
	{
		cout << "\n\t\t\t\t\t\t\x1b[31m   А Л Г О Р И Т М   К Р У С К А Л А  \x1b[30m\n\n";
		fout << "\n\t\t\t\t\t\t   А Л Г О Р И Т М   К Р У С К А Л А  \n\n";
		minimumSpanningTree = KruskalAlgorithm(pairs, matrix);
		flag = true;
		break;
	}

	case('p'):
	case('P'): // выбрали алгоритм Прима
	{
		cout << "\n\t\t\t\t\t\t\t\x1b[31m  А Л Г О Р И Т М   П Р И М А  \x1b[30m\n\n";
		fout << "\n\t\t\t\t\t\t\t  А Л Г О Р И Т М   П Р И М А  \n\n";
		minimumSpanningTree = primMST(pairs, matrix);
		flag = true;
		break;
	}

	case('b'):
	case('B'): // выбрали алгоритм Борувки
	{
		cout << "\n\t\t\t\t\t\t\t\x1b[31mА Л Г О Р И Т М   Б О Р У В К И  \x1b[30m\n\n";
		fout << "\n\t\t\t\t\t\t\tА Л Г О Р И Т М   Б О Р У В К И  \n\n";
		minimumSpanningTree = Boruvka(matrix);
		flag = true;
		break;
	}

	case('s'):
	case('S'): // выбрали выполнить 3 алгоритма поочерёдно
	{
		cout << "\n\x1b[36m В Р Е М Я   В Ы П О Л Н Е Н И Я   А Л Г О Р И Т М О В:   \x1b[30m\n";
		fout << "\n В Р Е М Я   В Ы П О Л Н Е Н И Я   А Л Г О Р И Т М О В:   \n";
		auto start = chrono::steady_clock::now();                  // начали отсчитывать время работы, т.к.  алгоритм чистый
		minimumSpanningTree = KruskalAlgorithm(pairs, matrix);     // вызвали алгоритм Крускала
		auto end = chrono::steady_clock::now();                    // закончили отсчёт времени
		cout << " Время выполнения алгоритма Крускала в мкс: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		fout << " Время выполнения алгоритма Крускала в мкс: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		minimumSpanningTree.clear();                               // очистка вектора


		start = chrono::steady_clock::now();                       // начали отсчитывать время работы, т.к.  алгоритм чистый
		minimumSpanningTree = primMST(pairs_1, matrix);            // вызвали алгоритм Прима
		end = chrono::steady_clock::now();                         // закончили отсчёт времени
		cout << " Время выполнения алгоритма Прима в мкс: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		fout << " Время выполнения алгоритма Прима в мкс: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		minimumSpanningTree.clear();                               // очистка вектора

		start = chrono::steady_clock::now();                       // начали отсчитывать время работы, т.к.  алгоритм чистый
		minimumSpanningTree = Boruvka(matrix);                     // вызвали алгоритм Прима
		end = chrono::steady_clock::now();                         // закончили отсчёт времени
		cout << " Время выполнения алгоритма Борувки в мкс: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		fout << " Время выполнения алгоритма Борувки в мкс: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		break;
	}

	// иначе - пользователь ввёл не тот ключ. Заканчиваем программу с ошибкой
	default:
		cout << "\n\x1b[31m ПЕРЕЗАПУСТИТЕ ПРОГРАММУ И ВВЕДИТЕ ЗНАЧЕНИЕ ИЗ СПИСКА КЛЮЧЕЙ!!!\n\x1b[30m";
		fout << "\n ПЕРЕЗАПУСТИТЕ ПРОГРАММУ И ВВЕДИТЕ ЗНАЧЕНИЕ ИЗ СПИСКА КЛЮЧЕЙ!!!\n";
		// закрываем файл считывания
		exit(0);
	}

	// счётчик веса в остовном дереве
	int Counter = 0;

	// если выбран только один алгоритм
	if (flag)
	{
		cout << "\x1b[36m С П И С О К   Р Ё Б Е Р:\x1b[30m \n";
		fout << " С П И С О К   Р Ё Б Е Р: \n";

		cout << " [";
		fout << " [";
		// проходим по остовному дереву минимального веса
		for (int i = 0; i < minimumSpanningTree.size(); i++)
		{
			cout << "(";
			fout << "(";
			cout << minimumSpanningTree[i].second.first + 1 << ", ";
			fout << minimumSpanningTree[i].second.first + 1 << ", ";

			cout << minimumSpanningTree[i].second.second + 1 << ", ";
			fout << minimumSpanningTree[i].second.second + 1 << ", ";

			cout << minimumSpanningTree[i].first;
			fout << minimumSpanningTree[i].first;
			//fout << minimumSpanningTree[i].first << endl;
			cout << ")";
			fout << ")";

			// выводим разделители между элементами
			if (i < minimumSpanningTree.size() - 1)
			{
				cout << ", ";
				fout << ", ";
			}// if

			// увеличиваем счётчик веса остовного дерева минимального веса - суммируем рёбра
			Counter = Counter + minimumSpanningTree[i].first;
		}// for i

		cout << "]";
		fout << "]";

		// выводим суммарный вес дерева минимального веса
		cout << "\n\n\x1b[32m В Е С   О С Т О В Н О Г О   Д Е Р Е В А:\x1b[30m " << Counter << endl;
		fout << "\n\n В Е С   О С Т О В Н О Г О   Д Е Р Е В А: " << Counter << endl;
	}// if


	// Выводим картинку с графом на экран
	OpenImage(NewGraph.adjacency_matrix());

	fout.close();
	// возвращаем обещанное значение в функцию
	return 0;
}
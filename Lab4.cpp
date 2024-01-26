/********************************************************************************
 * � � � � � � � � � � � �   � � � � � �  �4  � �   5   � � � � � � �   �  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab4                                               *
 * File Name     : Lab4. CPP                                                    *
 * Programmer(s) : ������� �.�.                                                 *
 * Modifyed By   :                                                              *
 * Created       : 19/09/23                                                     *
 * Last Revision : 18/10/23                                                     *
 * Comment(s)    : ���������, ��������� �������� ������ �����.  ��� �������     *
 *                 �������� ������ ������������ �����.                         *
 *                 ����������� �������� ������ ���� �����, �������� � �������� *
 *                 ������ � ��������� ��� ������.                               *
 ********************************************************************************/


#include <iostream>              // ����������� ������ �����/������
#include <vector>                // ������ � ��������� ��� �������� �������� ���������� � �������� ���������
#include <chrono>                // ������ �� ��������
#include <fstream>               // ������ � �������� �����/������ ��� �����
#include <iomanip>               // ���������� � ������������� setw
#include <graphviz/gvc.h>        // ���������� Graphviz ��� ������������ ����������� ����� �� ������� ���������
#include <opencv2/opencv.hpp>    // ���������, ������������� ��� ������� OpenCv

using namespace std;             // ���������� ������������ ��� std


/*******************************************************************/
/*            � � � � � � � � � �    � � � � � � � � �             */
/*******************************************************************/

// ���� � ����� ����� ����������� ���������
// ������� �����
// ����� ��� ������� ���������
//const char* FNAMEIN = "matrix_t4_001.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_002.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_003.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_004.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_005.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_006.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_007.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_008.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_009.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_010.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t4_011.txt";                // ���� � �������� ���������

// ����� ��� ������ �����
//const char* FNAMEIN = "list_of_edges_t4_001.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_002.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_003.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_004.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_005.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_006.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_007.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_008.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_009.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_010.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t4_011.txt";         // ���� �� ������� ����

// ����� ��� ������ ���������
// ������ � ������ �� ������������


// �������� �����
const char* FNAMEOUT = "Output_File.txt";




/*******************************************************************/
/*      � � � � � � � � � �    � � � � � � � �    � � � � � �      */
/*******************************************************************/

 // ���������� ������� ��� ���������� ����� ������ �� �����
ifstream fin;
// ���������� ������� ��� ���������� ������ ������ � ����
ofstream fout;




/*******************************************************************/
/*                 � � � � � � � �   � � � � � � �                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // ���� � ��������� ����������� �������� ���������
	int m_size;                                               // ������ ������� ��������� (���������� ������ � �����)

public:
	// �����������
	Graph();
	// ����������
	~Graph();
	// ����������� ������ ��� ��������� �������� �������
	const int GetSize();
	// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
	bool is_directed();
	// �������, ������������ ������� ���������
	vector<vector<int>> adjacency_matrix();
	// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
	int Weight(int Vi, int Vj);
	// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
	bool is_edge(int Vi, int Vj);
	// �������, ������������ ������ ������, ������� ������� v;
	vector<int> adjacency_list(int v);
	// �������, ������������ ������ ���� ���� �����;
	vector<pair<int, int>> list_of_edges_pairs();
	// � �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              � � � � � � � � �    � � � � � � �                 */
/*******************************************************************/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix);             // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ����� �� ����� � ���� ��������
void OpenImage(const vector<vector<int>>& adjacencyMatrix);               // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix);                             // �������, ������� ���������� ������� �� �����. �������� �� ��������

// ������ ������� � ������� ������
void Usloviya();

// ������ ������� ������ ���������
void Usloviya_1();

// �������������� ���������������� ����� � ����������� ���
void convertToUndirected(vector<vector<int>>& matrix);                    // ������� ��������� �� ������ ��� � ���������

// ����� ����� � ����������� �����
pair<int, int> getSmallestEdge(const vector<pair<int, int>> edges_pairs,  // ��� ����� �����, �������� � ���� ��� ������, ���������� ��
	                           vector<vector<int>> matrix);               // ������� ��������� �����

// �������, ������������ ������ ���� ���� ������������ �����;
vector<pair<int, int>> Symmetrical_Graph_Edges(vector<vector<int>> graph);// ������� ��������� ������������ �����

// �������� ���������
// �������� � ������� ������������. ���� � ���� ������ - ���� ������ ������������ i - ������ �� ����������
int find(vector<int> parent,                                              // ������ ������ ��������, � ������� ��������� �������
	     int vercicle);                                                   // ������� �������

// ������� ��� ����������� ���� �����������
// x � y - ��������, ������� �� ����� ���������� � ������������
void Union(vector<int>& parent,                                           // ������ ������ ��������, � ������� ��������� �������
	       int first_root,                                                // ������ ������� ���������, ������� ����� ����������
	       int second_root);                                              // ������ ������� ���������, ������� ����� ����������

// ������� ��� ���������� ��������� ��������
vector<pair<int, pair<int, int>>> KruskalAlgorithm(vector<pair<int, int>>& pairs,     // ������ ��� ������ ������������ ����� 
	                                               const vector<vector<int>> graph);  // ������� ��������� ����� 

// ������� ��� ���������� ��������� �����
vector<pair<int, pair<int, int>>> primMST(vector<pair<int, int>>& pairs,              // ������ ��� ������ ������������ ����� 
	                                      const vector<vector<int>> graph);           // ������� ��������� �����

// ������� ��� ���������� ��������� �������
vector<pair<int, pair<int, int>>> Boruvka(const vector<vector<int>> m_matrix);        // ������� ��������� �����

// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix);                                     // �������, ������� ���������� ������� � ����. �������� �� ��������




// ����������� - ���������� ������� �� �����
Graph::Graph()
{
	fin.open(FNAMEIN);            // ��������� ������ � ������
	if (!fin.is_open())           // ���� �� ������
	{
		cout << "����� � ����� ������ ���. ���������� ����������� ������";
		fin.close();              // ������� ���� ��� ������
		system("pause");
		exit(0);                  // ���������� ��������, ��������������� ���� � caller
	}// if (!fin.is_open())

	int value;                    // ��������� ����������� ������
	char key;                     // ���� ��� �������� ������������� �������� ������� ����� � �����
	bool spravka = true;          // ���� ��� ������ ������� �� �����
	vector<int> row;              // ������ ��� ���������� ������������� �������� �� ����� ���������
	vector<vector<int>> matrix;   // ��������������� ������� ���������

	// ������ ����� ������� �����, ����� ������������ ������� ������� �� ����� �������
	while (spravka)
	{
		cout << "\x1b[30m � � � � � � �   � � � �   � � �   <h>   � � �   � � � � � �   � � � � � � � � � : \x1b[30m";
		// ������������ ��� ���� ��� ����, ����� ���� �������, ����� �������� �� ����� ����
		cin >> key;
		cout << "\n �� �����: " << key << endl;

		// � ����������� �� �������� �����
		switch (key)
		{
			// ������ � �������� ���������
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";
			// ��������� ��������� ����� �� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);

			}// while (fin >> value)

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������ �� ������� ����
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � �\n\n\x1b[30m\n";

			// ��������� �������� �� ����� � ������
			// � ������� ����� ���������� � ������������ ����� ��� ��������: ��������� �������, �������� ������� � ��� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);
			}// while (fin >> value)

			// ������� ���� ������
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // ������ ������� ���������
			vector<vector<int>> vec_1(size_m);                // ������� ���������

			for (int i = 0; i < size_m; i++)                  // ����� ������ ������ ������ vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// ��������� ������� ���������
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 ������� - ��� ��� �����, ���� �� �� ������, �� ������ �� = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// ���������� ������� ���������
			m_matrix = vec_1;
			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// �������� �� �������� ���������
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";

			// ������ �� ����� ���������
			string line;
			int rowNumber = 0;            // ����� ������� ������

			// ������ ����������
			while (getline(fin, line))
			{
				// ���� ������ ������, ��������� ������� ������ ������
				if (line.empty())
				{
					matrix.push_back(std::vector<int>(m_size, 0));
				}
				// ������ �� ������
				else
				{
					// ������ ������
					vector<int> row;
					// ������� ����� ��� ������ �������� �� ������ line. ����� �� ����� ������������ iss ������ � ���������� >> ��� ���������� �������� �� ������.
					istringstream iss(line);
					// ��������� �������� ��� ������
					int value;

					// ������ �������� �� ����� � �������� ��� � ������ ������
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// �������� ������ � �������
					matrix.push_back(row);
				}// if (line.empty()) 

				// ����������� ����� ������
				rowNumber++;
			}// while (getline(fin, line)) 

			// ���� �������� - ��������� ���
			fin.close();

			m_size = matrix.size();                         // ������ ������� ���������

			std::vector<std::vector<int>> vec_1(m_size);    // ��� ������� ��������� �������� m_size

			for (int i = 0; i < m_size; i++)                // ����� ������ ������ ������ ��� ������� ���������
			{
				// ��������� ��������������� ������� ������ �� ����� �������
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // ��������� ��� ������� ��������� 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// ������� � ��� ��������, ������� ����������� ��� ������ � �����
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// �������� �������� � �������� ������� ���������
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������������ ������ �������
		case('h'):
		case('H'):
		{
			// ��������� ���� ����� ��������� ������� �� ������
			spravka = true;
			// ������� �������
			Usloviya();
			break;
		}

		// ����� - ������������ ��� �� ��� ����. ����������� ��������� � �������
		default:
			cout << "\n\x1b[31m ������������� ��������� � ������� �������� �� ������ ������!!!\n\x1b[30m";
			// ��������� ���� ����������
			fin.close();
			exit(0);
		}
	}
	// ��������� ���� ����������
	fin.close();
	// ���������� ������ ���������/ ��������������� ������� ���������
	m_size = m_matrix.size();
}

// ����������
Graph::~Graph()
{
	// ������ ���� - ������� ������������ �������������
}

// ������ ��� ��������� �������� �������
const int Graph::GetSize()
{
	return(m_size);
}


// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
bool Graph::is_directed()
{
	// ��� �� �������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ��������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ���� �����������������, �� ������� �����������, ��� ��� �� ����� ����� ������ ������ ������������
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // ������� ������������ ����� - ���� ���������������
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // �� ������� ������������ ����� - ���� �����������������
}


// �������, ������������ ������� ���������
vector<vector<int>> Graph::adjacency_matrix()
{
	// ������� ������� ���������
	return(m_matrix);
}


// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
int Graph::Weight(int Vi, int Vj)

{
	// ������ ������ ����� �� ��������� ���������� ��������
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "������! ����� ������� �� ����������\n";
		// ������� ������
		return(-1);
	}// if

	// ���� ���� ����������(� ������� ��������� �� 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "��� ����� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����� ����� ���������
		return(m_matrix[Vi][Vj]);
	}// if

	// ���� ���������������. ������� ��� ����
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "���� ���������������. ���� ����. ����������� �����������. ��� ���� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����
		return(m_matrix[Vi][Vj]);
	}// else if

	// ����� ����� ��������� ��� - ������� ������� ��������� ����� 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "����� ����� ��������� " << Vi << " � " << Vj << "���\n";
		// ������� ������� ��������
		return(m_matrix[Vi][Vj]);
	}// else if

	// ������� �������� ��-���������
	return(0);
}


// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
bool Graph::is_edge(int Vi, int Vj)
{
	// ������ ������ ����� �� ��������� ���������� �������� - ���� ���
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// �������, ��� ���� ���
		return(false);
	}// if

	// ������� ������� ��������� �� ����� 0 - ����� ����
	if (m_matrix[Vi][Vj] != 0)
	{
		// ������������, ��� ����� ����
		return(true);
	}// if

	// ������� ������� ��������� ������� - ����� ���
	if (m_matrix[Vi][Vj] == 0)
	{
		// ������������, ��� ����� ���
		return(false);
	}// if

}


// �������, ������������ ������ ������, ������� ������� v;
vector<int> Graph::adjacency_list(int v)
{
	// ������ ������
	vector<int> adjList;

	// �������� �� ���� �������� � ���������, ���� �� ����� ����� �������� v � ������� ��������
	for (int i = 0; i < m_size; i++)
	{
		// ���� ���� - ������� ������� �� �������
		if (m_matrix[v][i] != 0)
		{
			// �������� ������� � ������
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// ���������� ������ ������� ������
	return adjList;
}


// �������, ������������ ������ ���� ���� �����;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// ������ ���, ���������� ����� � ���� ���� ����������� ��� ������
	vector<pair<int, int>> edges_pairs;
	// ��� �� ���� ��������� ������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ���� ��������� �������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ������� �� �������
			if (m_matrix[i][j] != 0)
			{
				// ��������� ���� ������
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i

	// ������� ������ ���� (��� ������)
	return(edges_pairs);
}


// �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // ������ ��� ������(������ ����)
	vector<pair<int, int>> edges_inc;     // ������ ���� ����������� ������� v / ��������� �� ������� v
	edges = list_of_edges_pairs();        // �������� ��� ���� ������ �����

	// ������� ��� ����. ���� ���� �����������������, �� ��� ����� ���� (v,n) � (n, v) - ���������� ����������� ��� ������������� ������ �������. � ������� - ��������� ������� ������ ������
	for (int i = 0; i < edges.size(); i++)
	{
		// ������������� ������ ������� ����
		if (edges[i].first == v)
		{
			// �������� � ����� �����, ����������� ������� ������ �����
			edges_inc.push_back(edges[i]);
			// ����������� �������
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// ����������  ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                �������               */
/*--------------------------------------*/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix)
{
	// ��������� ������ ������� ���������. ���� ������ 19, �� ������� �� ������� �������
	if (adjacencyMatrix.size() <= 25)
	{
		bool key = false;
		// ��������� ������� ����� �� ������, ����� ������, ����� �� ��������� �� ��� ������
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// ���� ��� ����� ������ 1 ��� �������������, ������, ����� ��������� ��� � ������
				if (adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
					key = true;
			}
		}

		// ��������� ���� ��� ������ ����� � ������� DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// ������� ���� � ��������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� �� ����� 0, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] != 0)
					{
						// ������� ����� � ��������� ���� � ������� DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// ������� ���� ��� �������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� ����� 1, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] == 1)
					{
						// ������� ����� ��� �������� ���� � ������� DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// ��������� ���� � ��������� ����������
		file << "}" << std::endl;
		file.close();

		// ���������� ����������� ����� � ������� PNG � ������� ������� DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\n Graph image saved as graph.png" << endl;
	}

	// �������, ��� ���� ������� ��� ���������
	else
	{
		cout << "\n\n Graph image is not saved as graph.png. It is too big" << endl;
	}
	// ���������� �������� ��� �������� ������ OpenCV
	return "graph.png";
}


// ����� ����� �� �����
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// ��������� ����������� ������� ���������
	if (adjacencyMatrix.size() <= 25)
	{
		// �������� ���� � �����������, ���������� � ������� ������� drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// ��������� ����������� � ������� OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// ���������, ������� �� ��������� �����������
		if (img.empty()) {
			cout << "Could not open or find the image" << endl;
			return;
		}

		// ������� ���� � ��������� "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// ���������� ����������� � ����
		cv::imshow("Graph", img);
		// ����, ���� ������������ ������ ����� �������
		cv::waitKey(0);
		// ��������� ����
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
}


// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix)
{
	// ��������� ������� ����
	setlocale(0, "C");            // ������� ������ � �������� �������
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // ����� ������� ���������� ������

	// ��� �� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// ��� �� ��������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ������� �������
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // ����� ������� �������
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");

	// ���������� ��������� ��������
	return;
}


// ������ ������� � ������� ������
void Usloviya()
{
	cout << "\n\t\t\t\t/********************************************************************************\n";
	cout << "\t\t\t\t* � � � � � � � � � � � �   � � � � � �  �4  � �   5   � � � � � � �   �  +  +  *\n";
	cout << "\t\t\t\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                     *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab4                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab4. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : ������� �.�.                                                  *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                               *\n";
	cout << "\t\t\t\t* Created       : 19/09/23                                                      *\n";
	cout << "\t\t\t\t* Last Revision : 17/10/23                                                      *\n";
	cout << "\t\t\t\t********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   � � � � � � � : \n\n\x1b[30m";
	// ������� ������� � �������
	setlocale(0, "C");                       // ��������� ������� ����
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // ������� ������� ������ �����
	setlocale(LC_ALL, "Rus");                // ���������� ������� ����
	cout << " �������� ���� ������� �� ������:      ";
	setlocale(0, "C");                       // ��������� ������� ����
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // ������� ������ ������ ����� � ������������ ����� ������� � ��������� ���������
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // ������� ������� ������ � ������ � �������� ��������� �������
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // ���������� ������� ����

	return;                                 // ���������� ��������� ��������
}


// ������ ������� ������ ���������
void Usloviya_1()
{
	// ������� ������� � �������
	setlocale(0, "C");                       // ��������� ������� ����
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // ������� ������� ������ �����
	setlocale(LC_ALL, "Rus");                // ���������� ������� ����
	cout << " �������� ���� �������� �� ������:     ";
	setlocale(0, "C");                       // ��������� ������� ����
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // ������� ������ ������ ����� � ������������ ����� ������� � ��������� ���������
	cout << "  k " << (char)179 << " Kruskal's algorithm              ";                                                                                                         // ������� ������� ������ � ������ � �������� ��������� �������
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  p " << (char)179 << " Prim's algorithm                 ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  b " << (char)179 << " Boruvka's algorithm              ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  s " << (char)179 << " 3 algorithms alternately         ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	setlocale(LC_ALL, "Rus");               // ���������� ������� ����

	return;                                 // ���������� ��������� ��������
}


// �������������� ���������������� ����� � ����������� ���
void convertToUndirected(vector<vector<int>>& matrix)                    // ������� ��������� �� ������ ��� � ���������
{
	// ������ ������� ��������� - ���������� ������ � �����
	int size = matrix.size();
	// �������� �� ������� �������� ������� � ������ �� ������������
	// ��� �� �������
	for (int i = 0; i < size; i++)
	{
		// �� ��������, ������� � i+1-��
		for (int j = i + 1; j < size; j++)
		{
			if (matrix[i][j] != 0)
			{
				// ���� ���� ����� �� i � j, ������� ����� �� j � i
				matrix[j][i] = matrix[i][j];
			}// if (matrix[i][j] != 0) 

			else if (matrix[j][i] != 0)
			{
				// ���� ���� ����� �� j � i, ������� ����� �� i � j
				matrix[i][j] = matrix[j][i];
			}// else if (matrix[j][i] != 0) 
		}// for j
	}// for i

	// ���������� ��������� ��������
	return;
}


// ����� ����� � ����������� �����
pair<int, int> getSmallestEdge(const vector<pair<int, int>> edges_pairs,  // ��� ����� �����, �������� � ���� ��� ������, ���������� ��
	                           vector<vector<int>> matrix)                // ������� ��������� �����
{
	// ���� ������, ���������� ���������� �����
	pair<int, int> smallestEdge;
	// ���������� ��� ����� ��� ��������� � ������� ������������. ���������� �� - �������������
	int smallestWeight = numeric_limits<int>::max();

	// ��� �� ���� ��������� ������� ��� ������
	for (int i = 0; i < edges_pairs.size(); i++)
	{
		// �������� ��� �������� �����
		int weight = matrix[edges_pairs[i].first][edges_pairs[i].second];

		// ���������� � ������� ���������� ��������� ����
		if (weight < smallestWeight)
		{
			// ���������� ��� �����, ���� �� ������, ��� ������� ����������
			smallestWeight = weight;
			// ���������� ���� ������, ����������� �����
			smallestEdge = edges_pairs[i];
		}// if
	}// for i

	// ���������� ���� ������, ���������� ���������� �����
	return smallestEdge;
}


// �������, ������������ ������ ���� ���� ������������ �����;
vector<pair<int, int>> Symmetrical_Graph_Edges(vector<vector<int>> graph)   // ������� ��������� ������������ �����
{
	// ������ ���, ���������� ����� � ���� ���� ����������� ��� ������
	vector<pair<int, int>> edges_pairs;
	// ��� �� ���� ��������� ������
	for (int i = 0; i < graph.size(); i++)
	{
		// ��� �� ���� ��������� �������
		for (int j = 0; j < graph.size(); j++)
		{
			// ���� ������� �� �������
			if (graph[i][j] != 0)
			{
				// ��������� ���� ������
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)

		}// for j

	}// for i
	// ������� ������ ���� (��� ������)
	return(edges_pairs);
}


// �������� ���������
// �������� � ������� ������������. ���� � ���� ������ - ���� ������ ������������ i - ������ �� ����������
int find(vector<int> parent,                                              // ������ ������ ��������, � ������� ��������� �������
	     int vercicle)                                                    // ������� �������
{
	// ���������� ������ �����. �������: � ����� -1
	if (parent[vercicle] == -1)
	{
		return vercicle;
	}// if

	// ���������� �������� ������� ��� ������� �� ���� ������� ���� �� ����� �� ����� ���������
	return find(parent, parent[vercicle]);
}


// ������� ��� ����������� ���� �����������
// x � y - ��������, ������� �� ����� ���������� � ������������
void Union(vector<int>& parent,                                           // ������ ������ ��������, � ������� ��������� �������
	       int first_root,                                                // ������ ������� ���������, ������� ����� ����������
	       int second_root)                                               // ������ ������� ���������, ������� ����� ����������
{
	// ���������� ��� ��������� - ������ ������� ��������� ����������� �� ������, ������ �� �������� ���� ������. � ���� ���������� ������
	parent[first_root] = second_root;
	// ���������� ��������� ��������
	return;
}


// ������� ��� ���������� ��������� ��������
vector<pair<int, pair<int, int>>> KruskalAlgorithm(vector<pair<int, int>>& pairs,     // ������ ��� ������ ������������ ����� 
	                                               const vector<vector<int>> graph)   // ������� ��������� ����� 
{
	int V = graph.size(); // ���������� ������ � �����

	// ������� ������ ������, ���������� ��� �������. ���������� ������ ������� - ������ ������ ���������
	vector<int> parent(V, -1);

	// ������� ������ ��� �������� ����� ������������ ��������� ������ � ���� (���, (�������1, �������2))
	vector<pair<int, pair<int, int>>> minimumSpanningTree;

	// �������� �� ���� ������ � ��������������� �������
	while (!pairs.empty())
	{
		// �������� ��������� ����� ������������ ����
		pair<int, int> smallestEdge = getSmallestEdge(pairs, graph);

		// ������� ����� � ���������� �����
		pairs.erase(remove(pairs.begin(), pairs.end(), smallestEdge), pairs.end());

		// �������� �������� ������, ������������ ����� ������������ ����
		int first = smallestEdge.first;
		int second = smallestEdge.second;

		// ������� ������� - ����� ���������
		int set_first = find(parent, first);
		int set_second = find(parent, second);

		// ���������, ��������� �� �������� ������� � ����� ���������
		// ���� ���, �� ��������� ����� � �������� ������ � ���������� ���������
		if (set_first != set_second)
		{
			// ��������� ����� � �������������� ������ ������
			minimumSpanningTree.push_back(make_pair(graph[first][second], make_pair(first, second)));
			// ���������� ���������
			Union(parent, set_first, set_second);
		}// if
	}// while

	// ���������� ������ ��������� ������
	return minimumSpanningTree;
}


// �������� �����
// ������� ��� ���������� ��������� �����
vector<pair<int, pair<int, int>>> primMST(vector<pair<int, int>>& pairs,              // ������ ��� ������ ������������ ����� 
	                                      const vector<vector<int>> graph)            // ������� ��������� �����
{
	int V = graph.size();                // ���������� ������ � �����
	vector<bool> visited(V, false);      // ���������� �������

	// ����� ������������ ��������� ������ � ���� (���, (�������1, �������2))
	vector<pair<int, pair<int, int>>> minimumSpanningTree;

	// ��������� ������� - ������
	int StartVertex = 0;
	// ������� ���������� ��� ����������� � ������
	visited[StartVertex] = true;

	// ���������� ���� � �������� ������ �� ������� ������, ��� ����� ������, ����� - ������ �������� ���� ��������
	while (minimumSpanningTree.size() < V - 1)
	{
		// ���������� ��� ���������� ����� � ����������� ����� 
		int minWeight = numeric_limits<int>::max();
		// ��������� ������� �����, ������� �� ����� �������� � �������� ������
		int minSrc = -1;
		// �������� ������� �����, ������� �� ����� �������� � �������� ������
		int minDest = -1;
		// ������ �����, ������� ����� �������
		int indexToRemove = -1;

		// ����� ������������ �����, ������� ��������� ��� ���������� � ������������ �������
		for (int j = 0; j < pairs.size(); j++)
		{
			// ���������� ������ ���������� �����
			int src = pairs[j].first;
			// ���������� ����� ���������� �����
			int dest = pairs[j].second;

			// ���� ���� ������� ����������� ������, � ������� - ��������� �� ��������� ������, � ��� �����, ������� ����� �������� ����� ����� ��������� ������, ��� ����������
			if ((visited[src] && !visited[dest]) && graph[src][dest] < minWeight)
			{
				// ���������� ��� ����� �����
				minWeight = graph[src][dest];
				// ���������� ��������� ������� �����, ������� ����� ��������
				minSrc = src;
				// ���������� �������� ������� �����, ������� ����� ��������
				minDest = dest;
				// ���������� ������ ����� ��� ��������
				indexToRemove = j;
			}// if

		}// for j


		// �������� ���������� ������������� ����� �� ������ ����� `pairs`
		if (indexToRemove != -1)
		{
			pairs.erase(pairs.begin() + indexToRemove);

		}// if

		// ���������� ���������� ����� � ����������� �������� ������
		minimumSpanningTree.push_back(make_pair(minWeight, make_pair(minSrc, minDest)));

		// ��������� ��������� �������
		visited[minDest] = true;
	}// while

	// ���������� ������ ��������� ������
	return minimumSpanningTree;
}


// �������� �������
// ������� ��� ���������� ��������� �������
vector<pair<int, pair<int, int>>> Boruvka(const vector<vector<int>> m_matrix)         // ������� ��������� �����
{
	// ���������� ������ � �����
	int V = m_matrix.size();               
	// ����� ������������ ��������� ������ � ���� (���, (�������1, �������2))
	vector<pair<int, pair<int, int>>> minimumSpanningTree;
	// ���������� ���������
	vector <int> componenta(V);

	// ���������� ������ ������� - ��������� ���������� ���������. ��� ���������� ������
	for (int i = 0; i < V; i++)
	{
		componenta[i] = i;
	}// for i

	// ������ ���������� ������
	vector<bool> visited(m_matrix.size(), false);
	// ��������������� ���������� ��� ����������� ����� ������������ ����
	int min = numeric_limits<int>::max();
	// ��������� ��� �������� ������ �������, ������� �� ����� ��������� � ������
	int k;
	// ���� ���������� ����������� �����
	bool flag = false;
	// ������� ���������� ����
	int n = 0;

	// ������������ ��������� ��������� ���������
	// ���������� ������� 
	// ��� �� ���� ������� ������� ���������
	for (int i = 0; i < V; i++)
	{
		// ���� ������� i �� ����������� ���������� ���������
		if (!visited[i])
		{
			// ���������� �������
			// �������� ��������� �� ��������, � ������� �� ����� ���������
			for (int j = 0; j < V; j++)
			{
				// ����� ������������ ����� ��� i-� �������
				// ���� ����� ����� ��������� ���������� � ��� ������, ��� ���������� min, � ������� ����������� ������ ����������� ���������
				if (m_matrix[i][j] < min && m_matrix[i][j] != 0 && componenta[j] != componenta[i])
				{
					min = m_matrix[i][j];    // ��������� ����� ������������ ����
					k = j;                   // ��������� ����� �������, ������� ����� ��������� � ������
					flag = true;             // ���� ���������� �����
					visited[i] = true;       // �������� ��������� ��� ����������
				}// if

			}// for j

		}// if

		// ���� ����� ���������� �����
		if (flag)
		{
			n = n + 1;                      // ����������� ������� ����, ��� ��� ������� ����������
			// ��������� ����� � ������ ��������� ������
			minimumSpanningTree.push_back(make_pair(min, make_pair(i, k)));
			// �������� ����������� ������� ���������� ��� ����������
			visited[k] = true;
			// ��������� � ��������� ���������, ��� ��� ��� ������ � if ����� ����� ����������� ��������
			int e = componenta[k];

			// ����� ���������, ������������� ������ � ���� �� ������
			for (int j = 0; j < V; j++)
			{
				// ����������� ������ ������
				if (componenta[j] == e)
				{
					// ��������� � ������ �����. ������������ ������ ���������
					componenta[j] = componenta[i]; 
				}// if

			}// for j

		}// if

		// �������� �������� ��� ������ ���������� �����
		flag = false;
		k = -1;
		min = numeric_limits<int>::max();
	}// for i


	vector<int> odinakov; // ������ ��� �������� ������, ������� ����������� ������ ������
	int pos;              // ���������� ��� �������� ������ �������, ������� �� ����� ��������� � ������
	int vershina;         // ��������� �������, ������ ����� ���������� �����

	// ���� ���� ��������� �� ��� ���� � ���������, �� �������� �� ��������� ��������. � �������� ������ V-1 �����, �.�. �� ������, ���� �������� ������, �� ��� �������� ���� ��������
	if (n != V - 1)
	{
		// ������ �� ������� relax
		for (int i = 0; i < V; i++)
		{
			// ����� ������, ������� ����������� ������ ������
			for (int j = 0; j < V; j++)
			{
				if (componenta[j] == componenta[i])
				{
					// ��������� ����� �������, ������������� ������ ���������� ���������
					odinakov.push_back(j);
				}// if
			}// for j

			// ������ �� ������� "odinakov"
			for (int j = 0; j < odinakov.size(); j++)
			{
				// ����� ������, ������� ����������� ������ ������
				for (int k = 0; k < V; k++)
				{
					// ������� ������������ ���������� ������ �����������, �� �� ����� �� ����������
					if (m_matrix[odinakov[j]][k] < min && m_matrix[odinakov[j]][k] != 0 && componenta[k] != componenta[odinakov[j]])
					{
						min = m_matrix[odinakov[j]][k];
						pos = k;                     // ��������� ����� �������, ������� ����� ��������� � ������
						flag = true;                 // ���������� ���� ����������� ����
						vershina = odinakov[j];      // ��������� �������, ������ ����� ���������� �����
					}// if

				}// for k

			}// for j

			// ���� ����� �����
			if (flag)
			{
				n = n + 1;                           // ����������� ������� ����, ��� ��� ������� ����������
				// ��������� ����� � ������ ��������� ������
				minimumSpanningTree.push_back(make_pair(min, make_pair(vershina, pos)));
				int e = componenta[pos];
				// ����� ���������, ������������� ������ � ���� �� ������
				for (int w = 0; w < componenta.size(); w++)
				{
					// ����������� ������ ������
					if (componenta[w] == e)
					{
						// ��������� � ������ �����. ������������ ������ ���������
						componenta[w] = componenta[i];
					}// if

				}// for w

			}// if

			// ���� � ��� ��� ���� ���������� ���-�� ����, �� ������� �� �����
			if (n == V - 1)
			{
				break;
			}// if

			// �������� �������� ��� ������ ���������� �����
			flag = false;
			pos = -1;
			min = numeric_limits<int>::max();
			odinakov.clear();
		}// for i

	}// if

	// ���������� ������ ��������� ������
	return minimumSpanningTree;
}


// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix)                 // �������, ������� ���������� ������� � ����. �������� �� ��������
{
	// ��� �� ������� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		// ��� �� �������� �������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ��������� ������� ������� � ����
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// ���������� ��������� ��������
	return;
}

/*------------------------------------------------------------------------*/
/*            ������� �������           */
/*--------------------------------------*/
int main()
{
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");
	// ���� ������� - �����
	system("color F0");
	// ���� ������ � ����. ���������� - ������ ���
	bool print = false;
	// ����, �������� ������������� ��� ������
	char letter;
	// ������� ��� ������
	// ���� ������ ��������� �����
	vector<pair<int, int>> pairs;
	// ���� ������ ������������ �����
	vector<pair<int, int>> pairs_1;
	// ������� ��������� �����
	vector<vector<int>> matrix;
	// ������ ��������� ������ (���(�������1, �������2))
	vector<pair<int, pair<int, int>>> minimumSpanningTree;


	cout << "\t\t\t\t\t\t\x1b[34m    � � � � � �   �   � � � � � � �\x1b[30m\n\n\n";
	// ������� ������ �����. ����������� ���������� ��-���������
	Graph NewGraph;
	
	// ��������� ������� ���
	pairs = NewGraph.list_of_edges_pairs();
	pairs_1 = NewGraph.list_of_edges_pairs();

	// �������� �������� ������� ���������
	matrix = NewGraph.adjacency_matrix();

	// �����, ����� �� ������������ �������� � ���� ����������� ����������
	cout << " ������ �� �� �������� ������ � ����? ������� <o>, ���� ������, ��� ����� ������ ������ - ���� ���. �������: ";
	cin >> letter;                             // ���� �������������
	cout << "\n �� �����: " << letter;         // ���-������

	// ���� ������������ ����� ��������. ������������� ����
	if (letter == 'o' || letter == 'O')
	{
		print = true;

		fout.open(FNAMEOUT);           // ��������� ������ � ������
		if (!fout.is_open())           // ���� �� ������
		{
			cout << "����� � ����� ������ ���. ���������� ����������� ������";
			fin.close();               // ������� ���� ��� ������
			system("pause");
			exit(0);                   // ���������� ��������, ��������������� ���� � caller
		}// if (!fout.is_open())

		fout << "\t\t\t\t\t\t    � � � � � �   �   � � � � � � �\n\n\n";

	}// if (letter == 'o' || letter == 'O')

	// �� ����� �������� ������� ��������� ��� ������� ������
	if (NewGraph.GetSize() <= 100)
	{
		cout << "\n\n\t\t\t\t\x1b[35m     � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\x1b[30m\n\n";
		PrintMatrix(NewGraph.adjacency_matrix());

		fout << "\n\n\t\t\t\t     � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\n\n";
		PrintMatrToFile(NewGraph.adjacency_matrix());
	}// if


	// ���� ���� ���������������
	if (NewGraph.is_directed())
	{
		// ������ ����������� ���
		convertToUndirected(matrix);
		if (NewGraph.GetSize() <= 100)
		{
			cout << "\n\n\t\t\t\t\x1b[36m      � � � � � � �   � � � � � � � � �   � � � � � � � � � � � � �   � � � � �:\x1b[30m\n\n";
			PrintMatrix(matrix);

			fout << "\n\n\t\t\t\t      � � � � � � �   � � � � � � � � �   � � � � � � � � � � � � �   � � � � �:\n\n";
			PrintMatrToFile(matrix);
		}// if

		// ��������� ������� ��� ������ ������������ �����
		pairs.clear();
		pairs_1.clear();
		pairs = Symmetrical_Graph_Edges(matrix);
		pairs_1 = Symmetrical_Graph_Edges(matrix);
	}// if


	// ����� �������������, ����� �������� �� ����� �������
	char key;
	cout << "\n\x1b[33m � � � � � � �   � � � �   � �   � � � � � � � � �   � � � � � �: \x1b[30m\n";
	Usloviya_1();

	// ����, ������� ����������, ��� ���� ������� ���� �� ��� ������ ����������
	bool flag = false;
	// ���� ������������� ����� ���������
	cout << " ���� �����: ";
	cin >> key;
	// ���-������
	cout << " �� �����: " << key << endl;

	// ����� ���������
	switch (key)
	{

	case('k'):
	case('K'):// ������� �������� ��������
	{
		cout << "\n\t\t\t\t\t\t\x1b[31m   � � � � � � � �   � � � � � � � �  \x1b[30m\n\n";
		fout << "\n\t\t\t\t\t\t   � � � � � � � �   � � � � � � � �  \n\n";
		minimumSpanningTree = KruskalAlgorithm(pairs, matrix);
		flag = true;
		break;
	}

	case('p'):
	case('P'): // ������� �������� �����
	{
		cout << "\n\t\t\t\t\t\t\t\x1b[31m  � � � � � � � �   � � � � �  \x1b[30m\n\n";
		fout << "\n\t\t\t\t\t\t\t  � � � � � � � �   � � � � �  \n\n";
		minimumSpanningTree = primMST(pairs, matrix);
		flag = true;
		break;
	}

	case('b'):
	case('B'): // ������� �������� �������
	{
		cout << "\n\t\t\t\t\t\t\t\x1b[31m� � � � � � � �   � � � � � � �  \x1b[30m\n\n";
		fout << "\n\t\t\t\t\t\t\t� � � � � � � �   � � � � � � �  \n\n";
		minimumSpanningTree = Boruvka(matrix);
		flag = true;
		break;
	}

	case('s'):
	case('S'): // ������� ��������� 3 ��������� ���������
	{
		cout << "\n\x1b[36m � � � � �   � � � � � � � � � �   � � � � � � � � � �:   \x1b[30m\n";
		fout << "\n � � � � �   � � � � � � � � � �   � � � � � � � � � �:   \n";
		auto start = chrono::steady_clock::now();                  // ������ ����������� ����� ������, �.�.  �������� ������
		minimumSpanningTree = KruskalAlgorithm(pairs, matrix);     // ������� �������� ��������
		auto end = chrono::steady_clock::now();                    // ��������� ������ �������
		cout << " ����� ���������� ��������� �������� � ���: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		fout << " ����� ���������� ��������� �������� � ���: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		minimumSpanningTree.clear();                               // ������� �������


		start = chrono::steady_clock::now();                       // ������ ����������� ����� ������, �.�.  �������� ������
		minimumSpanningTree = primMST(pairs_1, matrix);            // ������� �������� �����
		end = chrono::steady_clock::now();                         // ��������� ������ �������
		cout << " ����� ���������� ��������� ����� � ���: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		fout << " ����� ���������� ��������� ����� � ���: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		minimumSpanningTree.clear();                               // ������� �������

		start = chrono::steady_clock::now();                       // ������ ����������� ����� ������, �.�.  �������� ������
		minimumSpanningTree = Boruvka(matrix);                     // ������� �������� �����
		end = chrono::steady_clock::now();                         // ��������� ������ �������
		cout << " ����� ���������� ��������� ������� � ���: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		fout << " ����� ���������� ��������� ������� � ���: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
		break;
	}

	// ����� - ������������ ��� �� ��� ����. ����������� ��������� � �������
	default:
		cout << "\n\x1b[31m ������������� ��������� � ������� �������� �� ������ ������!!!\n\x1b[30m";
		fout << "\n ������������� ��������� � ������� �������� �� ������ ������!!!\n";
		// ��������� ���� ����������
		exit(0);
	}

	// ������� ���� � �������� ������
	int Counter = 0;

	// ���� ������ ������ ���� ��������
	if (flag)
	{
		cout << "\x1b[36m � � � � � �   � � � � �:\x1b[30m \n";
		fout << " � � � � � �   � � � � �: \n";

		cout << " [";
		fout << " [";
		// �������� �� ��������� ������ ������������ ����
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

			// ������� ����������� ����� ����������
			if (i < minimumSpanningTree.size() - 1)
			{
				cout << ", ";
				fout << ", ";
			}// if

			// ����������� ������� ���� ��������� ������ ������������ ���� - ��������� ����
			Counter = Counter + minimumSpanningTree[i].first;
		}// for i

		cout << "]";
		fout << "]";

		// ������� ��������� ��� ������ ������������ ����
		cout << "\n\n\x1b[32m � � �   � � � � � � � � �   � � � � � �:\x1b[30m " << Counter << endl;
		fout << "\n\n � � �   � � � � � � � � �   � � � � � �: " << Counter << endl;
	}// if


	// ������� �������� � ������ �� �����
	OpenImage(NewGraph.adjacency_matrix());

	fout.close();
	// ���������� ��������� �������� � �������
	return 0;
}
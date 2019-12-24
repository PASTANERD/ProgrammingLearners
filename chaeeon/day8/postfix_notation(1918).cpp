/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1918
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>

using namespace std;

class Node{
    private:
        char character;
        Node* left_child;
        Node* right_child;
    public:

        Node(char data){
            character = data;
            left_child = new Node();
            right_child = new Node();
        }
        void set_Node(Node* left, Node* right){
            left_child = left;
            right_child = right;
        }
        Node* get_left_child(){
            return left_child;
        }

        Node* get_right_child(){
            return right_child;
        }
};

class PostfixTree{
    private:
        Node* thisnode;
    public:
        PostfixTree(){
            thisnode = new Node();
        }
        void pushNode(char character){
            
            thisnode = new Node(character);

        }
        Node getNode(){
            return *thisnode;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string N;
    cin >> N;
    cin.ignore();

    return 0;
}

/*
 * A*B+C    => CAB*+
 *              +
 *           *     C
 *        A     B
 *       
 * 
 * A+B*C    => ABC*+
 *              +
 *          A       *
 *              B       C
 * 
 * A*(B+C)  => ABC+*
 *              *
 *          A       +
 *              B       C
 */
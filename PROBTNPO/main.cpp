#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

typedef struct Node{
   // store operator or operand
   string data;
   // only valid for operator
   int precedence;
   struct Node* parent;
   struct Node* left;
   struct Node* right;
}CNode, *PNode;

PNode CreateNode(const string& x)
{
   PNode p = new CNode;
   p->parent = p->left = p->right = NULL;
   p->data = x;
   return p;
}

bool IsOperator(const string& x)
{
   // Since the only impact of parentheses () is on precedence,
   // they are not considered as operators here
   return ((x.length() == 1) &&
           (x[0] == '*' ||
            x[0] == '/' ||
            x[0] == '+' ||
            x[0] == '-'));
}

bool IsLeftParenthesis(const string& x)
{
   return x == "(";
}

bool IsRightParenthesis(const string& x)
{
   return x == ")";
}

bool IsOperand(const string& x)
{
   int y;
   stringstream ss(x);
   if (ss >> y) return true;
   else return false;
}

int GetPrecedence(const string& x)
{
   assert(IsOperator(x));
   if (x[0] == '*' || x[0] == '/') return 2;
   else return 1;
}

PNode CreateInfixTree(const string& exp)
{
   // create a dummy root with minimal precedence
   // its content is trivial
   PNode root = CreateNode("0");
   root->precedence = INT_MIN;

   // the previous operand of current operator
   PNode preOperand = NULL;
   // the previous operator of current operator
   PNode preOperator = root;
   // the impact of preceding parenthesis, if any
   int correction = 0;

   string token;
   stringstream ss(exp);

   while (ss >> token)
   {
      if (IsOperand(token))
      {
         preOperand = CreateNode(token);
      }
      else if (IsOperator(token))
      {
         PNode p = CreateNode(token);
         p->precedence = GetPrecedence(token) + correction;
         if (p->precedence > preOperator->precedence)
         {
            p->left = preOperand;
            preOperator->right = p;
            p->parent = preOperator;
         }
         else
         {
            preOperator->right = preOperand;
            PNode q = preOperator->parent;
            while (p->precedence <= q->precedence) q = q->parent;

            p->left = q->right;
            q->right = p;
            p->parent = q;
         }
         preOperand = NULL;
         preOperator = p;

      }//else if (IsOperator(token)
      else if (IsLeftParenthesis(token))
      {
         correction += 2;
      }
      else if (IsRightParenthesis(token))
      {
         correction -= 2;
      }
      else
      {
         cout << "illegal token found: " << token << endl;
         break;
      }
   }//while

   if (preOperand == NULL)
       cout << "illegal expression: cannot end with operator: "
            << preOperator->data << endl;
   else preOperator->right = preOperand;

   // delete dummy root
   PNode realRoot = root->right;
   delete root;
   if (realRoot) realRoot->parent = NULL;
   return realRoot;
}

void PostOrderPrintTree(PNode node)
{
   if (node)
   {
      PostOrderPrintTree(node->left);
      PostOrderPrintTree(node->right);
      cout << node->data << " ";
   }
}

int main()
{
   // valid operators: + - * / ( )
   // valid operands: integers
   // whitespace separated as: ( 1 + 2 ) * 3
   string exp;
   getline(cin, exp);
   PNode root = CreateInfixTree(exp);
   PostOrderPrintTree(root);
   cout << endl;
}

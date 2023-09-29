#include <bits/stdc++.h>

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

#define PI 3.141592653589793
#define MOD 1000000007
#define MOD1 998244353
#define inf 1e18;

#define int long long
#define ll long long
#define vll vector<long long>
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define setup(x) setprecision(x) << fixed
#define in insert
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define pr pair<int, int>
#define pq priority_queue<ll>
#define mpq priority_queue<ll, vector<ll>, greater<ll>>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

#define rep(x, y, z) for (int x = (y); x <= (z); ++x)
#define per(x, y, z) for (int x = (y); x >= (z); --x)

#define watch(x) cerr << #x << " = " << x << "\n"

#define test \
  int _T;    \
  cin >> _T; \
  while (_T--)
#define inp(x) \
  int x;       \
  cin >> x;
#define out(x) cout << x << '\n';
#define all(x) (x).begin(), (x).end()
#define Sort(x) sort(all(x))
#define endl '\n'
#define setup(x) setprecision(x) << fixed
#define trav(i, v) for (auto &i : v)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define take(v) trav(i, v) cin >> i;
#define show(v)                \
  trav(i, v) cout << i << " "; \
  cout << "\n";

#define Max(x, y, z) max(x, max(y, z))
#define Min(x, y, z) min(x, min(y, z))
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)

using namespace std;
// Definition for a binary tree node
class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int data)
  {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};
int depth(TreeNode *root)
{
  if (root == nullptr)
    return -1;
  return 1 + depth(root->left);
}
int height(TreeNode *root)
{
  if (!root)
    return 0;
  int lh = height(root->left);
  int rh = height(root->right);
  return max(lh, rh) + 1;
}

bool isBalanced(TreeNode *root)
{
  if (!root)
    return true;

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    return true;

  return false;
}
bool isBstCheck(TreeNode *root, int minValue, int maxValue)
{
  if (!root)
  {
    return true; // An empty tree is a BST
  }

  if (root->data < minValue || root->data > maxValue)
  {
    return false; // Node's dataue is outside the dataid range
  }

  // Check the left and right subtrees
  return isBstCheck(root->left, minValue, root->data - 1) &&
         isBstCheck(root->right, root->data + 1, maxValue);
}

bool isBST(TreeNode *root)
{
  return isBstCheck(root, INT_MIN, INT_MAX);
}
bool isPerfectCheck(TreeNode *root, int depth, int level = 0)
{

  if (root == nullptr)
    return true;
  if (root->left == nullptr && root->right == nullptr)
  {
    return depth == level;
  }

  else if (root->right == nullptr || root->left == nullptr)
  {
    return false;
  }

  return isPerfectCheck(root->left, depth, level + 1) && isPerfectCheck(root->right, depth, level + 1);
}

bool isPerfect(TreeNode *root)
{
  int d = depth(root);
  return isPerfectCheck(root, d);
}
int countNodes(TreeNode *root)
{
  if (root == nullptr)
    return 0;
  return countNodes(root->left) + countNodes(root->right) + 1;
}
bool isCompleteCheck(TreeNode *root, int numberOfNodes, int index = 0)
{
  if (root == nullptr)
    return true;
  if (index >= numberOfNodes)
    return false;
  return isCompleteCheck(root->left, numberOfNodes, 2 * index + 1) && isCompleteCheck(root->right, numberOfNodes, 2 * index + 2);
}
bool isComplete(TreeNode *root)
{
  int numberOfNodes = countNodes(root);
  cout << "Number of nodes " << numberOfNodes << endl;
  return isCompleteCheck(root, numberOfNodes);
}
bool isFullBinaryTree(TreeNode *root)
{
  if (root == nullptr)
    return true;
  if (!root->left && !root->right)
    return true;
  if (root->right && root->left)
    return isFullBinaryTree(root->right) && isFullBinaryTree(root->left);
  return false;
}

bool isFull(TreeNode *root)
{
  if (!root)
    return true;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    auto node = q.front();
    q.pop();
    if (node->left && !node->right)
      return false;
    if (node->right && !node->left)
      return false;
    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
  }
  return true;
}
bool symmetricHelp(TreeNode *left, TreeNode *right)
{
  if (!left || !right)
    return left == right;
  if (left->data != right->data)
    return false;
  return symmetricHelp(left->left, right->right) && symmetricHelp(left->right, right->left);
}
bool isSymmetric(TreeNode *root)
{
  return symmetricHelp(root->left, root->right);
}
void buildTreeFromLevelOrder(TreeNode *&root, ifstream &fin)
{
  queue<TreeNode *> q;
  // cout << "Enter data for the root node : ";
  int data;
  fin >> data;
  if (data != -1)
  {
    root = new TreeNode(data);
    q.push(root);
  }

  while (!q.empty())
  {
    auto node = q.front();
    data = node->data;
    q.pop();
    // cout << " Enter leftNode data for  " << data << " :";
    int leftNodeData;
    fin >> leftNodeData;
    if (leftNodeData != -1)
    {
      node->left = new TreeNode(leftNodeData);
      q.push(node->left);
    }
    // cout << "Enter rightNodeData for " << data << " :";
    int rightNodeData;
    fin >> rightNodeData;
    if (rightNodeData != -1)
    {
      node->right = new TreeNode(rightNodeData);
      q.push(node->right);
    }
  }
}

int32_t main()
{
  IOS;
  ifstream fin("input.txt");

  TreeNode *root = nullptr;
  buildTreeFromLevelOrder(root, fin);
  bool ans = isFull(root);
  if (ans)
    cout << "Full Binary Tree" << endl;
  else
    cout << "Not Full Binary Tree" << endl;
}
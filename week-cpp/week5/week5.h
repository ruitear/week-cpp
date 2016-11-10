#include"mytitle.h"

//day1 ���������ĵ�һ�������ڵ�
struct listNode{
	int data;
	listNode* next;
};
//�����������ľ�����������������������������֮ǰ���ܵĽ������⣬���������Ƿ��л�������⣬�����ǲ��ǿ����ҵ�һ�����õĽ���취�أ�
//���ǿ϶��ģ��԰ɣ���������������ǲ��ǻ��кܶ������ķ��������磬����һ��hash����hash��������ר�Ÿ��㽲һ�£����ȱ���һ������������
//ÿ���ڵ㶼�浽���hash���У�Ȼ������ڶ�����������hash���в�ѯ��ǰ�����Ľڵ��Ƿ������hash�С���������hash��������֮ǰ�������⣬����
//��β��ͷ��ӡһ��������������������ཻ�����ԣ�֮ǰ�����ģ������Ǵ��ཻ�Ľڵ㿪ʼ�������غϵģ������ǲ��ǿ���������������ջ���ֱ������
//����������ÿ���ڵ㣬����֮��ջ������ÿ�����������һ��Ԫ�أ�Ȼ�����αȽϣ��ҵ���һ������ͬ�Ľڵ�����ཻ�ĵ�һ���ڵ�֮ǰ�Ľڵ㡣��Ȼ��������
//��ջ�Ļ����϶��������õݹ�԰ɣ�ֻ��Ҫ�ݹ�����ڻ��ݵĹ������ҵ���һ������ͬ�Ľڵ�����ˡ�    ������Щ�������������򵥵İ취�𣿵�Ȼ��
//�ཻ���������ཻ�Ľڵ㿪ʼ�����غϵģ�Ҳ����˵��������ǰ�������β�����룬Ȼ��ӽ϶̵�������ͷ�����ͷ��Ӧ���ϳ��������Ǹ��ڵ㿪ʼ����
//�����αȽϱ������ǲ��ǵ�һ����ͬ�Ľڵ㣬��������Ҫ�ҵĽڵ㡣Ϊ�˾���Ҫ�ȱ����õ����������ĳ���,�԰ɣ�
//�������������ĳ��ȵ�ʵ��
unsigned int getLength(listNode* head)
{
	unsigned int nLength = 0;
	listNode* pNode = head;
	while (pNode != NULL)
	{
		++nLength;
		pNode = pNode->next;
	}
	return nLength;
}
listNode* find1stCommon(listNode* head1,listNode* head2)
{
	unsigned int nLength1=getLength(head1);
	unsigned int nLength2=getLength(head2);
	int diffLength = nLength1 - nLength2;
	listNode* longNode = head1;
	listNode* shortNode = head2;
	if (diffLength < 0)
	{
		longNode = head2;
		shortNode = head1;
		diffLength = abs(diffLength);
	}
	//���ó�������diffLength
	for (int i = 0; i < diffLength; ++i)
	{
		longNode = longNode->next;
	}
	while ((longNode != NULL) && (shortNode != NULL) && (longNode != shortNode))
	{
		longNode = longNode->next;
		shortNode = shortNode->next;
	}
	listNode* commonNode = longNode;
	return commonNode;
}


//����عˣ��������ı���
//�������ı�����������ľ���ǰ�򡢺�������������ǰ��-�����ң�����-���Ҹ�������-�����
struct binaryTreeNode{
	int data;
	binaryTreeNode* left;
	binaryTreeNode* right;
};
void visitNode(binaryTreeNode* T)
{
	if (T->data)
		cout << T->data << "-";
}
//ǰ�����
void preOrder(binaryTreeNode* T)
{
	if (T != NULL)
	{
		visitNode(T);
		preOrder(T->left);
		preOrder(T->right);
	}
}
//�������
void postOrder(binaryTreeNode* T)
{
	if (T != NULL)
	{	
		preOrder(T->left);
		preOrder(T->right);
		visitNode(T);
	}
}
//�������
void inOrder(binaryTreeNode* T)
{
	if (T != NULL)
	{
		preOrder(T->left);
		visitNode(T);
		preOrder(T->right);
	}
}
//�ص���Ŀ�У��ڶ�������ǰ������У���һ���ڵ��������ĸ��ڵ㣬������������и��ڵ��ֵ�����е��м䣬�������Ľڵ��ڸ�����ߣ�
//��������ֵ�ڸ����ұߣ�ǰ�����{1,2,4,7,3,5,6,8}���������{4,7,2,1,5,3,8,6}����ǰ�����1�����Ǹ��ڵ��ֵ���ٿ������������
//��ȷ��1��λ�ú�����������λ�ã�Ҳ����1ǰ�ߵ�������������������ߵ��ĸ�������������ͬ��ǰ�������1��ߵ�ǰ3����������������
//�ĸ���������������ô���������������ǲ�������ͬ���ķ������Ϳ��Եݹ�ȷ��ÿ���ڵ��λ�����أ�
binaryTreeNode* constructTree(int* benginPreOrder, int* endPreOrder, int* benginInOrder, int* endInOrder)
{
	int rootValue = benginPreOrder[0];
	binaryTreeNode* root = new binaryTreeNode();
	root->data = rootValue;
	root->left = root->right = NULL;

	if (benginPreOrder == endPreOrder)
	{
		if (benginPreOrder == endPreOrder&&*benginInOrder == *endPreOrder)
		{
			return root;
		}
		else
			throw exception("Invalid Input.");
	}
	//����Ѯ�������Ҹ��ڵ��ֵ
	int* rootInOrder = benginInOrder;
	while (rootInOrder<=endInOrder&&*rootInOrder!=rootValue)
	{
		++rootInOrder;
	}
	if (rootInOrder == endInOrder&&*rootInOrder != *endInOrder)
	{
		throw exception("Invalid Input.");
	}
	int leftLength = rootInOrder - benginInOrder;
	int* leftPreOrderEnd = benginPreOrder + leftLength;
	if (leftLength > 0)
	{
		root->left = constructTree(benginPreOrder + 1, leftPreOrderEnd, benginInOrder, rootInOrder - 1);
	}
	if (leftLength < endPreOrder - benginPreOrder)
	{
		root->right = constructTree(leftPreOrderEnd + 1, endPreOrder, rootInOrder+1,endInOrder);
	}
	return root;
}
binaryTreeNode* constructTree(int* preOrder, int* inOrder,int length)
{
	if (preOrder == NULL || inOrder == NULL || length <= 0) return NULL;
	
	constructTree(preOrder, preOrder + length-1, inOrder, inOrder + length-1);
}
//day2 
//�ַ����滻
//��������ֱ�۵�Ȼ��������԰ɣ���ǰ�������������һ���ո�Ͱ��������������λ���ٷ���%RT��Ҳ��һ������ҪŲ����߶��еġ�
//����˼·��������ǴӺ����ǰŲ�ǲ��ǻ�úܶ࣬���ȱ���һ���ַ����������ж��ٸ��ո�Ȼ���ڼ����滻֮����ַ����Ƕ೤��
//�����Ӻ���ǰ�����ǲ���Ч�ʸ��˺ܶ࣬�����˴�ǰ����Ų���Ĺ��̡�
void replaceSpace(char str[])
{
	if (str == NULL) return;
	int numSpace = 0;
	int length = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++length;
		if (str[i] == ' ') ++numSpace;
		++i;
	}
	int newLength = length + 2 * numSpace;
	int indexOri = length;
	int indexNew = newLength;
	while (indexOri >= 0 && indexNew > indexOri)
	{
		if (str[indexOri] == ' ')
		{
			str[indexNew--] = 'T';
			str[indexNew--] = 'R';
			str[indexNew--] = '%';
		}
		else
		{
			str[indexNew--] = str[indexOri];
		}
		--indexOri;
	}

}
//�ֲ����:�������´�ӡ������
//������Ҫ��������±�����������Ŀ�ǲ��ǻ����ƣ�֮ǰ�Ӵ��ı������ǻ�����ǰ�к������������Ҫ����������±����������������������һ��
//���ڵ�1���ڵ�һ�㣬���ȱ�����������һ�������������ӽڵ�2,3��Ϊ���ܹ�������2,3��Ӧ�ð����Ǵ��������浽���أ����ǽ��ŷ������ֲ��ǰ�
//�մ������ұ�����1������2������3��Ҳ����2��ǰ���ȱ�������3�ں�ߺ���������ǲ����뵽�˶��У��Ƚ��ȳ������ʣ��ǵģ��ѽڵ����������
//���δ浽һ�������У�Ҳ���ǵ����Ǳ�����һ���ڵ��ʱ��Ͱ�����ڵ�������ӽڵ���ӣ�����ӡ���������еľ�����˴��ϵ��µı�����
void printTopToBottom(binaryTreeNode* root)
{
	if (!root)return;
	deque<binaryTreeNode*>dequeTree;
	dequeTree.push_back(root);
	while (dequeTree.size())
	{
		binaryTreeNode* node = dequeTree.front();
		dequeTree.pop_front();
		cout << node->data << "-";
		if (node->left)dequeTree.push_back(node->left);
		if (node->right)dequeTree.push_back(node->right);
	}
}
//��֮���δ�ӡ������
//��֮���δ�ӡ������������һ���еķֲ���ϵ��´�ӡ���Ǻ�������⣬��ͬ���ǣ����������Ĳ�������ż��һ���ֻ��������Һʹ�������
//�����Ե�˼·����Ȼ�ֲ㣬���ǰ�ÿ��浽һ�����������ˣ���ʲô�����أ�һ��˳���Ƚ������һ�����ź���ȳ�����ôͳһ�أ��ǲ���
//�ȽϾ��ᣬ��������ǰ��������һ��������������㿴����������������Ľ���˳���ǲ��ǾͿ���ͳһ���Ƚ��ȳ������Ƚ�����أ�Ϊ�˼�
//�������������������ջ�ֱ�������������ʱ���ż���Ĳ�ʱ��ڵ㣬�������һ��ֻ�и��ڵ㣬���ڵ�����������ڵڶ��㣬����������
//������������һ��ջ����ջ˳����������������������������Ǵ�������Ĺ��̣����������ڶ����ÿ���ڵ��ʱ�����ǵ��ӽڵ�����
//���㣬�������ұ�����Ҳ���Ǳ����ڶ���ڵ��ʱ��������������ջ˳�������Һ���������ӡ��ʱ����Ǵ������ң����������ķ�ʽ����
//������ȥ��������ջ��û��Ԫ�ص�ʱ���ֹͣ�����ģ�ΪʲôҪ������ջ����һ������ô�����Ǻ���ʵ�ֵģ���ô��һ�������أ����ǣ�
//Ҳ�ǲ��ò����ģ�
void printZhi(binaryTreeNode* root)
{
	if (!root)return;
	stack<binaryTreeNode*> nodeLevel[2];
	int currentLevel = 0;
	int nextLevel = 1;
	nodeLevel[currentLevel].push(root);
	while (!nodeLevel[0].empty() || !nodeLevel[1].empty())
	{
		binaryTreeNode* node = nodeLevel[currentLevel].top();
		nodeLevel[currentLevel].pop();
		cout << node->data << "-";
		if (currentLevel == 0)
		{
			if (node->left != NULL)
			{
				nodeLevel[nextLevel].push(node->left);
			}
			if (node->right != NULL)
			{
				nodeLevel[nextLevel].push(node->right);
			}
		}
		else
		{
			if (node->right != NULL)
			{
				nodeLevel[nextLevel].push(node->right);
			}
			if (node->left != NULL)
			{
				nodeLevel[nextLevel].push(node->left);
			}
		}
		if (nodeLevel[currentLevel].empty())
		{
			currentLevel = 1 - currentLevel;
			nextLevel =1- nextLevel;
		}
	}
}
//day3
//�������
//����������ȣ�����ֻ��һ�����ڵ����Ⱦ�Ϊ1�������ڵ�ֻ������������������������ȼ�1��ͬ��ֻ����������ʱ�򣬾�����������ȼ�1��
//�Ƕ���ڼ������������������������������ȥ��������������ȼ�1������������˼·�ݹ���ȥ���ͺܷ����ˣ��������£�
int treeDepth(binaryTreeNode* root)
{
	if (root==NULL)return 0;
	int leftDepth = treeDepth(root->left);
	int rightDepth = treeDepth(root->right);

	return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}
//�ж�һ�����ǲ���ƽ���������
//ƽ��������Ķ��壺������������ڵ���������������������1����ô�Ǿ���һ��ƽ���������
//�������нڵ�õ���Ȳ�
bool isBalanceTree(binaryTreeNode* root)
{
	if (root == NULL)return true;
	int left = treeDepth(root->left);
	int right = treeDepth(root->left);
	if (abs(left - right) > 1)return false;
	return isBalanceTree(root->left) && isBalanceTree(root->right);
}
//���ö������ĺ�����������ģ������������������ڵ�ʱ�������ҽڵ����Ѿ��������ˣ�ֻҪ��ס����������������ȾͿ����жϵ�ǰ���ǲ���ƽ�������
bool IsBalanced(binaryTreeNode* root, int* pDepth)
{
	if (root == NULL)
	{
		*pDepth = 0;
		return true;
	}
	int left, right;
	if (IsBalanced(root->left, &left)&& IsBalanced(root->left, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
//����ֻ�㺯�ĺ���
bool isBalanceTree2(binaryTreeNode* root)
{
	int depth = 0;
	return IsBalanced(root, &depth);
}
//N!ĩβ0�ĸ���
//N!��ĩβ0�ĸ�������������2��5�ܹ��ճɶ��ٶԣ�Ҳ������min(count(2),count(5)),�������г��ֵĸ�����Ȼ2��Ƶ�ʱ�5�ߣ�����ֻ��Ҫ��5�ж��ٸ���OK��
int countN0(int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int j = i;
		while (j % 5 == 0)
		{
			count++;
			j /= 5;
		}
	}
	return count;
}
//����ͳ��5�ĸ��������⣬��һ���򵥵ĵ��ƹ�ʽ������֤����˵����Ϊ��Ҳ֤������ֻ�����ˣ��˴�����������
//��f��x����ʾΪĩβ0�ĸ�������0<N<5,f��N!��=0����N>=5ʱ��f��N!��=k+f��k!��,����k=n/5��
//ת���ɺ͵���ʽ��������f(N!)=[N/5]+[N/5^2]+[N/5^3]+....�ܴ���һ��Kʹ��5^K>N,[5^K]=0,����[N/5]��ʾ������N������5�ı�������һ��5��
//[N/5^2]��ʾ������N������5^2�ٹ���һ��5���������ƣ�
int countN00(int n)
{
	int count = 0;
	while (n)
	{
		count += n / 5;
		n /= 5;
	}
	return count;
}
//day4
//�������ľ���
//��������⣬����ֻҪ���ڵ�һ�ν����������������Ϳ��Ե��˶԰ɣ����µ���һ���ݹ�ʵ�ֵĴ��룺
void mirrorBinaryTree(binaryTreeNode* root)
{
	if (root == NULL)return;
	if (root->left == NULL&&root->right == NULL)return;
	binaryTreeNode* temp=root->left;
	root->left = root->right;
	root->right = temp;
	if (root->left)	 mirrorBinaryTree(root->left);
	if (root->right) mirrorBinaryTree(root->right);
}
//�Գƶ�����
//�ж�һ���������ǲ��ǶԳƵģ�����������������ǲ��Ǹ��ϱ߶������ľ�������Ȱ�һ������������Ȼ����ͨ��ĳ�ֱ�����ʽ�����磬ǰ�к��������
//��������ǰ��ı��������ǲ�����ͬ�ģ���ͬ�Ļ���˵���ǶԳƵĶ԰ɣ������жϵĹ����У�Ҫע�⣬��һ����������ÿ���ڵ��Ԫ��ֵ����ͬ��ʱ��ʹ����
//�ԳƵģ��õ��ı������ж���һ���ģ��˴����Ի�һ��ʾ��ͼ����Ϊ�˱�������������ֵ�����ģ��ѽڵ������������NULL������ǽ����������У��ǲ��Ǿ�
//���Խ���ˣ���Ȼ��һЩżȻ�����Ҳ����־���ǰ��ı�������һ�������Կ��ǽڵ��NULL����Ǳ���á����ˣ����˾���ʽ�Ľ����������Ƚ��о����
//�������ֱ�ӱȽ��ǲ���Ҳ�ǿ��е��أ���ǰ�к���������е�����һ�֣�����һ�ֺ����ԳƵı�����ʽ���������ȽϾͿ����ж�������ǲ��ǶԳƵ��ˣ�
//��ȻҲҪ�����ڶ��������нڵ���ͬ�������ͬ��Ҫ�ȽϽڵ������������NULL�����
//���¸�����������ǰ������������ң���Ȼ������һ����ǰ��ԳƵı���������ķ�ʽ��
bool isSymmetrical(binaryTreeNode* root1, binaryTreeNode* root2)
{
	if (root1 == NULL&&root2 == NULL)return true;
	if (root1 == NULL || root2 == NULL)return false;
	if (root1->data != root2->data)return false;
	return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
}
bool isSymmetricalTree(binaryTreeNode* root)
{
	return isSymmetrical(root, root);
}
//N!�Ķ����Ʊ�ʾ�����λ1��λ��
//�ڶ�������һ��2����10���ж϶�����λ�Ƿ�Ϊ0����Ϊ0�����Ա�2����������һλ����Ϊ1�����ܱ�2������N!�����һλ1��������Ϳ���ת��Ϊ���Ա����ٸ�
//2�����������ˣ���day3�������ǲ��Ǻ��񣿺��ˣ�������ʵ�ֵĴ��룺
int lowestOne(int n)
{
	int count = 0;
	while (n)
	{
		n >>= 1;
		count += n;
	}
	return count;
}
//day5
//���л�������
//���л��Ĺ�����ֻ��Ҫ�����ڱ����Ĺ����п��ǵ����ڵ��NULLֵ�;�OK��
void serializeTree(binaryTreeNode* root,ostream& stream)
{
	if (root == NULL)
	{
		stream << "#,";
	}
	stream << root->data << ',';
	serializeTree(root->left, stream);
	serializeTree(root->right, stream);
}
//�����л�
//�����л��������������л��Ľ����һ������
bool ReadStream(istream& stream, int* number)
{
	if (stream.eof())
		return false;

	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream >> ch;
	int i = 0;
	while (!stream.eof() && ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;
	if (i > 0 && buffer[0] != '$')
	{
		*number = atoi(buffer);
		isNumeric = true;
	}

	return isNumeric;
}
void deserializeTree(binaryTreeNode* root, istream& stream)
{
	int num;
	if (ReadStream(stream, &num))
	{
		root = new binaryTreeNode();
		root->data = num;
		root->left = NULL;
		root->right = NULL;

		deserializeTree(root->left, stream);
		deserializeTree(root->right, stream);
	}
}
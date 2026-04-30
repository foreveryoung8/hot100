/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        
        // 第一步：创建所有新节点，用 map 记录旧节点 -> 新节点的映射
        unordered_map<Node*, Node*> nodeMap;
        Node* current = head;
        while (current) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }
        
        // 设置新节点的 next 和 random 指针
        current = head;
        while (current) {
            if (current->next) {
                nodeMap[current]->next = nodeMap[current->next];
            }
            if (current->random) {
                nodeMap[current]->random = nodeMap[current->random];
            }
            current = current->next;
        }
        
        return nodeMap[head];
    }
};
// @lc code=end


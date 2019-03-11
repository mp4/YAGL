#pragma once

#include <string>
#include <unordered_map>
#include <set>

namespace YAGL {

	class Node {
	public:
		int id;
	};
	std::unordered_map<Node, std::vector<Node>> graph;

	//removes all references to the node
	template <class T>
	void RemoveNode(std::unordered_map<T, std::set<T>> graph, T & node) inline
	{
		if (graph.count(node))
		{
			graph.erase(node);

			for (auto iter = graph.begin(); iter != graph.end(); ++iter)
			{
				if (*iter.count(node))
				{
					*iter.erase(node);
				}
			}
		}
	}

	template <class T>
	void AddEdge(std::unordered_map<T, std::set<T>> graph, T & node0, T & node1) inline//adds edge from node 0 to node 1(digraph) 
	{
		graph[node0].insert(node1);
	}

	//add node manually to the graph

};
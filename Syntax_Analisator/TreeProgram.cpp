#include "TreeProgram.h"

//void TreeProgram::MakeFirstNode(std::string text)
//{
//	first = new NodeProgram(text);
//	iterator = first;
//
//}
//
//void TreeProgram::MakeInNode(std::string text)
//{
//	iterator->in = new NodeProgram(text);
//	iterator->in->parent = iterator;
//	iterator = iterator->in;
//}
//
//void TreeProgram::MakeNextNode(std::string text)
//{
//	iterator->next = new NodeProgram(text);
//	iterator->next->parent = iterator;
//	iterator = iterator->next;
//}
//
//void TreeProgram::MakeNode(std::string text, int k)
//{
//	switch (k)
//	{
//	case 0:
//		MakeFirstNode(text);
//		break;
//
//	case 1:
//		MakeNextNode(text);
//		break;
//
//	case 2:
//		MakeInNode(text);
//	}
//}
//
//TreeProgram::TreeProgram(std::string text)
//{
//	std::string buf;
//	int whereToGo = 0;
//
//	for (int i = 0; i < text.size(); i++)
//	{
//		buf.push_back(text[i]);
//
//		switch (text[i])
//		{
//		case ';':
//			if (first == nullptr)
//				MakeFirstNode(buf);
//			else
//				MakeNode(buf, whereToGo);
//
//			buf.clear();
//			break;
//
//		case '(':
//			if (first == nullptr)
//				MakeFirstNode(buf);
//			else
//				MakeNode(buf, whereToGo);
//
//			buf.clear();
//			break;
//
//		case ')':
//			if (first == nullptr)
//				MakeFirstNode(buf);
//			else
//				MakeNode(buf, whereToGo);
//
//			buf.clear();
//			break;
//
//		case '{':
//			if (first == nullptr)
//				MakeFirstNode(buf);
//			else
//				MakeNode(buf, whereToGo);
//
//			buf.clear();
//			break;
//
//		case '}':
//			break;
//
//		case '[':
//			if (first == nullptr)
//				MakeFirstNode(buf);
//			else
//				MakeNode(buf, whereToGo);
//
//			buf.clear();
//			break;
//
//		case ']':
//			if (first == nullptr)
//				MakeFirstNode(buf);
//			else
//				MakeNode(buf, whereToGo);
//
//			buf.clear();
//			break;
//
//		case ',':
//			if (first == nullptr)
//				MakeFirstNode(buf);
//			else
//				MakeNode(buf, whereToGo);
//
//			buf.clear();
//			break;
//
//		default:
//		}
//	}
//
//}
import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * 通过链表实现栈，包括基本的功能：入栈、出栈，栈统计信息、清空栈、查询元素是否在栈内、将指定元素的栈顶端元素全部出栈（即指定元素成为新的栈顶）等功能。
 * @author LuoPeng
 * 2013-11-23
 */

public class StackByLinkTest {
	public static void main(String[] args) {
		System.out.println("1----------------入栈");
		System.out.println("2----------------出栈");
		System.out.println("3----------------参看元素总个数");
		System.out.println("4----------------查找指定元素");
		System.out.println("5----------------清空链表");
		System.out.println("6----------------遍历链表");
		System.out.println("0----------------退出");
		
		int input = 0;
		BufferedReader br = null;
		String line = null;
		StackByLink obj = new StackByLink();
		
		br = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			System.out.println("----------------请输入操作编号：----------------");
			try {
				if ((line = br.readLine()) != null) {
					line = line.trim();
					input = Integer.valueOf(line);
					switch(input) {
					case 1:
						System.out.println("请输入要入栈的值：");
						input = Integer.valueOf(br.readLine());
						obj.push(input);
						break;
					case 2:
						obj.pop();
						break;
					case 3:
						System.out.println("链表中元素总个数为：" + obj.size());
						break;
					case 4:
						System.out.println("请输入要查找的值：");
						input = Integer.valueOf(br.readLine());
						if (obj.find(input))
							System.out.println(input + "在链表中。");
						else 
							System.out.println(input + "不在链表中。");
						break;
					case 5:
						obj.makeEmpty();
						break;
					case 6:
						obj.traverse();
						break;
					case 0:
						return;
					default:
						System.out.println("请输入指定范围的数字。");
					}
				}
			} catch (Exception e1) {
				System.out.println("Error:----------------输入的数字不合法。");
			}
		}
	}

}

/*
 * 链表 
 */
class StackByLink {
	
	private int elementCount = 0;//链表中元素的总个数
	private Node head = null;//链表的头
	
	public StackByLink () {}
	
	/* 出栈 */
	public void pop() {
		if (isEmpty()) {
			System.out.println("当前栈为空，不能执行出栈操作。");
			return;
		}
		System.out.println("出栈的元素是：" + head.getValue());
		//删除最前面的元素
		head = head.getNext();
		elementCount--;
	}
	
	/* 入栈 */
	public void push(int value) {
		Node node = new Node(value);
		node.setNext(head);
		head = node;
		elementCount++;
	}
	
	/* 链表中元素的个数 */
	public int size() {
		return elementCount;
	}
	
	/* 查找指定的元素是否存在 */
	public boolean find(int value) {
		Node node = head;
		while (node != null) {
			if (node.getValue() == value) {
				return true;
			}
			else {
				node = node.getNext();
			}
		}
		return false;
	}
	
	/* 清空栈中的所有元素时 */
	public void makeEmpty () {
		head = null;
		elementCount = 0;
	}
	
	/* 判断栈是否为空 */
	private boolean isEmpty() {
		if (elementCount == 0)
			return true;
		else
			return false;
	}
	
	/* 链表的遍历 */
	public void traverse () {
		System.out.println("当前链表中元素的个数是：" + size());
		System.out.print("各个元素的值如下：");
		Node node = head;
		while (node != null) {
			System.out.print(node.getValue());
			node = node.getNext();
		}
		System.out.println();
	}
}

/*
 * 链表的节点
 */
class Node {
	
	private int value;//元素的值
	private Node next = null;//指向链表的下一个元素
	
	public Node (int value) {
		this.value = value;
		this.next = null;
	}
	
	public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}

	public Node getNext() {
		return next;
	}

	public void setNext(Node next) {
		this.next = next;
	}
}

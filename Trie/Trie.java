/*
Author: Ziqi Tan
*/

class TrieNode {	
	// children
	private TrieNode[] children;
	
	// Whether current node is an end node.
	private boolean isEnd;
	private final int R = 128;  // Depends on the size of the character set
	private int appearTimes;
	private boolean hasChildren;
	private String word;
	
	// Constructor
	public TrieNode() {
		isEnd = false;
		children = new TrieNode[R];
		appearTimes = 0;
		hasChildren = false;
	}
	
	public boolean containsChar(char ch) {
		return children[ch] != null;
	}
		
	// getter and setter
	public boolean isEnd() {
		return isEnd;
	}
	public void setEnd(boolean _isEnd) {
		isEnd = _isEnd;
	}
	
	// get Char by Char
	public TrieNode get(char ch) {
		return children[ch];
	}
	
	// put char
	public void put(char ch, TrieNode node) {
		children[ch] = node;
		hasChildren = true;
	}
	
	// get children
	public TrieNode[] getChildren() {
		return children;
	}
	
	// get appear times
	public int getAppearTimes() {
		return appearTimes;
	}
	
	// get has children
    public boolean hasChildren() {
        return hasChildren;
    }
    
    // get current word
    public String getCurrentWord() {
    	return word;
    }
    // set current word
    public void setCurrentWord(String _word) {
    	word = _word;
    }
	
}

public class Trie {
	
	private TrieNode root;
	
	// Constructor
	public Trie() {
		root = new TrieNode();
	}
	
	// Get root
	public TrieNode getRoot() {
		return root;
	}
	
	// Inserts a word into the trie.
    public void insert(String word) {
        TrieNode node = root;
        for( int i = 0; i < word.length(); i++ ) {
        	char currentChar = word.charAt(i);
        	if( !node.containsChar(currentChar) ) {
        		node.put(currentChar, new TrieNode());
        	}
        	node = node.get(currentChar);
        }
        node.setEnd(true);
        node.setCurrentWord(word);
    }
    
    // Returns if the word is in the trie. 
    public boolean search(String word) {
    	TrieNode node = root;
    	for( int i = 0; i < word.length(); i++ ) {
    		char currentChar = word.charAt(i);
    		if( node.containsChar(currentChar) ) {
    			node = node.get(currentChar);
    		}
    		else {
    			return false;
    		}
    	}
		return node.isEnd();       
    }
    
    // Returns if there is any word in the trie that starts with the given prefix.
    public boolean searchPrefix(String prefix) {
    	TrieNode node = root;
    	for( int i = 0; i < prefix.length(); i++ ) {
    		char currentChar = prefix.charAt(i);
    		if( node.containsChar(currentChar) ) {
    			node = node.get(currentChar);
    		}
    		else {
    			return false;
    		}
    	}  	
		return true;        
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("HelloWorld!");
		/*Trie trie = new Trie();

		trie.insert("apple");
		trie.search("apple");   // returns true
		trie.search("app");     // returns false
		trie.startsWith("app"); // returns true
		trie.insert("app");   
		trie.search("app");     // returns true
		*/
	}

}

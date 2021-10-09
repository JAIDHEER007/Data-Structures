class node:
    def __init__(self):
        self.children = [None] * 26
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = node()
    
    def insert(self, word):
        '''
        :param word: string that needs to be inserted to Trie
        :return: boolean
        Inserts a string into Trie in O(L) time
        
        L is length of the string
        '''
        curr = self.root
        for ch in word:
            index = ord(ch) - ord('a')
            if curr.children[index] is None:
                curr.children[index] = node()
            curr = curr.children[index]

        curr.isEnd = True

    def search(self, key):
        '''
        :param word: string that needs to be searched in the Trie

        Searches for string in the Trie in O(L) time
        
        L is length of the string
        '''
        curr = self.root
        for ch in key:
            index = ord(ch) - ord('a')
            if curr.children[index] is None: return False
            curr = curr.children[index]
        return curr.isEnd

    def startsWith(self, key):
        curr = self.root
        for ch in key:
            index = ord(ch) - ord('a')
            if curr.children[index] is None: return False
            curr = curr.children[index]
        return True


if __name__ == '__main__':
    tree = Trie()

    tree.insert("jaidheer")
    tree.insert("jaiveer")

    print(tree.search("jai"))
    print(tree.search("jaidheer"))
    print(tree.startsWith("jai"))
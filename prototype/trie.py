class TrieNode:
    def __init__(self, letter):
        self.letter = letter
        self.children = {}
        self.isWord = False
        self.full_word = None


class Trie:
    def __init__(self):
        self.root = TrieNode("*")

    def add_word(self, word):
        cur = self.root
        for letter in word:
            if letter not in cur.children:
                cur.children[letter] = TrieNode(letter)

            cur = cur.children[letter]

        cur.isWord = True
        cur.full_word = word

    def check_word(self, word):
        cur = self.root

        for letter in word:
            if letter not in cur.children:
                return False
            cur = cur.children[letter]

        return cur.isWord

    def all_words_from_node(self, start_node):
        words = []

        for key, val in start_node.children.items():
            if val.isWord:
                words.append(val.full_word)
            res = self.all_words_from_node(val)
            words = words + res
        return words

    def give_possible_words(self, prefix):
        cur = self.root
        for letter in prefix:
            if letter not in cur.children:
                return ""

            cur = cur.children[letter]
        possibilities = self.all_words_from_node(cur)
        return possibilities


t = Trie()
with open("words/words.txt") as f:
    for word in f.readlines():
        t.add_word(word.strip())


while True:
    user_input = input("Word: ")
    # if user_input == "exit":
    #    break
    print(t.give_possible_words(user_input)[:5])

import java.io.*;
import java.util.*;

public class Main {
    static InputReader in = new InputReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        new Solution().solve();
        out.close();
    }

    static class Solution {
        void solve() {
            Trie trie = new Trie();
            trie.insert("hahaha");
            trie.insert("haha");
            trie.insert("lol");
            trie.insert("lul");
            trie.remove("haha");
            trie.remove("lol");
            String s = in.next();
            if (trie.has(s)) {
                out.println("YES");
            }
            else {
                out.println("NO");
            }
        }

        class TrieNode {
            TrieNode[] children;
            int countChildren;
            int countWords;
            int level;

            TrieNode(int level) {
                this.children = new TrieNode[Trie.ALPHABET_SIZE];
                this.countChildren = 0;
                this.countWords = 0;
                this.level = level;
            }
        }

        class Trie {
            static final int ALPHABET_SIZE = 26;
            TrieNode root;

            Trie() {
                this.root = new TrieNode(0);
            }

            void insert(String word) {
                TrieNode node = this.root;
                for (int i = 0; i < word.length(); i++) {
                    int childIndex = word.charAt(i) - 'a';
                    if (node.children[childIndex] == null) {
                        node.children[childIndex] = new TrieNode(node.level + 1);
                        node.countChildren++;
                    }
                    node = node.children[childIndex];
                }
                node.countWords++;
            }

            boolean has(String word) {
                TrieNode node = this.root;
                for (int i = 0; i < word.length(); i++) {
                    int childIndex = word.charAt(i) - 'a';
                    if (node.children[childIndex] == null) {
                        return false;
                    }
                    node = node.children[childIndex];
                }
                return node.countWords > 0;
            }

            /**
             * Delete a word from the trie
             * @param word
             * @return true if word exists in the tree
             */
            boolean remove(String word) {
                return this.remove(word, this.root);
            }

            /**
             * Delete a word from the trie
             * @param word
             * @param node
             * @return true if word exists in the tree
             * A node is deallocated if:
             * + It is the end of no word
             * + It has no child
             */
            boolean remove(String word, TrieNode node) {
                if (node == null) {
                    return false;
                }

                if (node.level == word.length()) {
                    if (node.countWords > 0) {
                        node.countWords--;
                        return true;
                    }
                    return false;
                }

                int childIndex = word.charAt(node.level) - 'a';
                TrieNode child = node.children[childIndex];

                boolean existsWord = remove(word, child);

                if (existsWord && child.countWords == 0 && child.countChildren == 0) {
                    node.children[childIndex] = null;
                    node.countChildren--;
                }

                return existsWord;
            }
        }
    }

    static class InputReader {
        static final int MAX_NUM_EMPTY_LINES = 1;
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream inStream) {
            reader = new BufferedReader(new InputStreamReader(inStream));
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String line = null;
                    int numEmptyLines = 0;
                    while (true) {
                        line = reader.readLine();
                        if (line != null) break;
                        numEmptyLines++;
                        if (numEmptyLines == MAX_NUM_EMPTY_LINES) return null;
                    }
                    tokenizer = new StringTokenizer(line);
                }
                catch (IOException e) {
                    throw new RuntimeException("Input Error");
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char nextChar() {
            return next().charAt(0);
        }
    }
}

import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class Main {
    private static InputReader in = new InputReader(System.in);
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    public static void main(String[] args) {
        // Get the number of layers
        int nLayers = in.nextInt();

        // Root
        int rootIndex = in.nextInt();
        Vertex root = new Vertex(rootIndex);
        BinaryTree binaryTree = new BinaryTree(root);

        // Remaining vertices
        ArrayList<Vertex> lastLayer = new ArrayList<>();
        lastLayer.add(root);

        for (int i = 1; i < nLayers; i++) {
            ArrayList<Vertex> currentLayer = new ArrayList<>();
            for (int j = 0; j < lastLayer.size(); j++) {
                Vertex v = lastLayer.get(j);
                v.addLeft(new Vertex(in.nextInt()));
                v.addRight(new Vertex(in.nextInt()));
                currentLayer.add(v.left);
                currentLayer.add(v.right);
            }
            lastLayer = currentLayer;
        }

        // Traversal
        System.out.print("Pre-order traversal: ");
        binaryTree.preOrderTraversal();
        System.out.print("In-order traversal: ");
        binaryTree.inOrderTraversal();
        System.out.print("Post-order traversal: ");
        binaryTree.postOrderTraversal();
    }
}

class Vertex {
    Vertex left = null;
    Vertex right = null;
    int index = -1;

    public Vertex(int index) {
        this.index = index;
    }

    public void addLeft(Vertex left) {
        this.left = left;
    }

    public void addRight(Vertex right) {
        this.right = right;
    }
}

class BinaryTree {
    Vertex root = null;

    public BinaryTree(Vertex root) {
        this.root = root;
    }

    // Pre-order traversal
    private void preOrder(Vertex v) {
        if (v == null) return;

        System.out.print(v.index + " ");
        preOrder(v.left);
        preOrder(v.right);
    }

    public void preOrderTraversal() {
        preOrder(root);
        System.out.println();
    }

    // In-order traversal
    private void inOrder(Vertex v) {
        if (v == null) return;

        inOrder(v.left);
        System.out.print(v.index + " ");
        inOrder(v.right);
    }

    public void inOrderTraversal() {
        inOrder(root);
        System.out.println();
    }

    // Post-order traversal
    public void postOrder(Vertex v) {
        if (v == null) return;

        postOrder(v.left);
        postOrder(v.right);
        System.out.print(v.index + " ");
    }

    public void postOrderTraversal() {
        postOrder(root);
        System.out.println();
    }
}

// Inputreader class
public class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream inStream) {
        reader = new BufferedReader(new InputStreamReader((inStream)));
        tokenizer = null;
    }

    public String next() {
        while ((tokenizer == null) || (!tokenizer.hasMoreTokens())) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            catch (Exception e) {
                e.printStackTrace();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public char nextChar() {
        return next().charAt(0);
    }

    public int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
    }
}
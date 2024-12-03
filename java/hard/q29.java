import java.util.ArrayList;
import java.util.List;

class Node {
    String name;
    boolean isFile;
    List<Node> children;

    Node(String name, boolean isFile) {
        this.name = name;
        this.isFile = isFile;
        this.children = new ArrayList<>();
    }
}

class FileSystem {
    private Node root;
    private Node current;

    public FileSystem() {
        root = new Node("/", false);
        current = root;
    }

    public void createDirectory(String dirName) {
        current.children.add(new Node(dirName, false));
        System.out.println("Directory created: " + dirName);
    }

    public void addFile(String fileName) {
        current.children.add(new Node(fileName, true));
        System.out.println("File added: " + fileName);
    }

    public void deleteEntry(String name) {
        boolean found = false;
        for (int i = 0; i < current.children.size(); i++) {
            Node child = current.children.get(i);
            if (child.name.equals(name) && child.isFile) {
                current.children.remove(i);
                System.out.println("Entry deleted: " + name);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Entry not found: " + name);
        }
    }

    public void changeDirectory(String dirName) {
        for (Node child : current.children) {
            if (child.name.equals(dirName) && !child.isFile) {
                current = child;
                System.out.println("Changed directory to: " + dirName);
                return;
            }
        }
        System.out.println("Directory not found: " + dirName);
    }

    public void displayTree(Node node, int depth) {
        System.out.println("-".repeat(depth) + node.name);
        for (Node child : node.children) {
            displayTree(child, depth + 1);
        }
    }

    public void display() {
        displayTree(current, 0);
    }
}

public class Main {
    public static void main(String[] args) {
        FileSystem fs = new FileSystem();

        System.out.println("\nTest Case 1: Create Directories and Display");
        fs.createDirectory("Dir1");
        fs.createDirectory("Dir2");
        fs.display();
        // Expected Output:
        // /
        // -Dir1
        // -Dir2

        System.out.println("\nTest Case 2: Add Files and Display");
        fs.addFile("File1.txt");
        fs.addFile("File2.txt");
        fs.display();
        // Expected Output:
        // /
        // -Dir1
        // -Dir2
        // -[File] File1.txt
        // -[File] File2.txt

        System.out.println("\nTest Case 3: Create Duplicate Entries");
        fs.createDirectory("Dir1");
        fs.addFile("File1.txt");
        fs.display();
        // Expected Output:
        // Duplicate directory/file names should not be allowed.

        System.out.println("\nTest Case 4: Delete Directory");
        fs.deleteEntry("Dir1");
        fs.display();
        // Expected Output:
        // /
        // -Dir2
        // -[File] File1.txt
        // -[File] File2.txt

        System.out.println("\nTest Case 5: Change Directory");
        fs.changeDirectory("Dir2");
        fs.createDirectory("SubDir1");
        fs.display();
        // Expected Output:
        // Dir2
        // -SubDir1
    }
}

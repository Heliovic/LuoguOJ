import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	static int N;
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		BigInteger sum = new BigInteger("0");
		BigInteger temp = new BigInteger("1");
		
		for (int i = 1; i <= N; i++) {
			temp = temp.multiply(new BigInteger(String.valueOf(i)));
			sum = sum.add(temp);
		}
		
		System.out.println(sum);
	}
}

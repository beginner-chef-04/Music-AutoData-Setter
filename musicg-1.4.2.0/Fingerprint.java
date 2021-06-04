import com.musicg.fingerprint.FingerprintSimilarity;
import com.musicg.wave.Wave;


public class Fingerprint{
	public static void main(String[] args) {
		System.out.println("Hello World!");

		Wave wave = new Wave("./Enter-music-name.wav");
		Wave wave1 = new Wave("./Enter-short-clipname.wav"); 
		FingerprintSimilarity fingerprintsimilarity = wave.getFingerprintSimilarity(wave1);
		float score = fingerprintsimilarity.getScore();
		float similarity = fingerprintsimilarity.getSimilarity();
		System.out.println("score : " + score + " similarity : " + similarity);

	}
}
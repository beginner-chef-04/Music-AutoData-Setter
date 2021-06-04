from glob import glob
import os

audio_files = [os.path.basename(x) for x in glob('C:\\Users\\The humour guy 004\\Desktop\\My Music Project-working\\/*.mp3')]
file1 = open("All_original_names.txt","w") 
for audio_file in audio_files[:]:
    file1.write(os.path.splitext(audio_file)[0]+'\n')
print()
print()
file1.close() 
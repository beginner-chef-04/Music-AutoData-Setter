import os
import sys
import json
import spotipy
import webbrowser
import spotipy.util as util
from json.decoder import JSONDecodeError
from spotipy.oauth2 import SpotifyClientCredentials
from mutagen.easyid3 import EasyID3 
from mutagen.id3 import ID3,APIC,error
from mutagen.mp3 import MP3
from urllib import request
import requests


cid = '59a2661e0044430eac6eff4406e9e54f'
secret = '8d832b544a9947eda61307857eb3d8eb'

c_c_m = SpotifyClientCredentials(client_id=cid, client_secret=secret)
sp = spotipy.Spotify(client_credentials_manager=c_c_m)

file1 = open("All_names_after_c++.txt","r") 
names=[line.rstrip() for line in file1.readlines()]
file1.close() 

file2 = open("All_original_names.txt","r") 
original_names=[line.rstrip() for line in file2.readlines()]
file2.close() 


i=0
for name in names[:]: 
    print("Song name searched : " + name)
    print()
    results = sp.search(q='track:' + name, type='track',limit=1,offset=0, market='IN')
    print(results)
    if len(results):
	    image_url = results['tracks']['items'][0]['album']['images'][0]['url']
	    album_name = results['tracks']['items'][0]['album']['name']
	    artist_name = results['tracks']['items'][0]['artists'][0]['name']
	    track_name = results['tracks']['items'][0]['name']
	    print("Album : " + album_name)
	    print("Artist : " + artist_name)
	    print("Image : " + image_url)
	    print("Track Name : " + track_name)
	    print()
	    
	    audiofile = EasyID3(original_names[i] + ".mp3")
	    audiofile["artist"] = artist_name
	    audiofile["album"] = album_name
	    audiofile["title"] = track_name
	    audiofile.save(v2_version=3)

	    audiofile = ID3(original_names[i] + ".mp3")
	    imagedata=request.urlopen(image_url).read()
	    audiofile.delall(u"APIC")
	    audiofile.add(APIC(encoding=3,mime='image/jpeg',type=3,desc=u"Cover",data=imagedata))# id3canbeused in mp3 with.tags.add
	    audiofile.save(v2_version=3)
	    print("done !")
	    
	    src ='C:\\Users\\The humour guy 004\\Desktop\\My Music Project-working\\'+ original_names[i] +'.mp3'
	    dst =track_name + '.mp3'
	    os.rename(src,dst) 
	    i=i+1
    
file1 = open("All_names_after_c++.txt","r+")
file1 = truncate(0)
file1.close()
file2 = open("All_original_names","r+")
file2 = truncate(0)
file2.close()    

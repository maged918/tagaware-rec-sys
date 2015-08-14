from lxml import *
import requests
from lxml import etree 


tree = etree.parse("/Users/ahmaddiaa/Desktop/tagaware-rec-sys/Hangman.java.xml")
loopnested =  tree.xpath('.//loop/if')
print len(loopnested)
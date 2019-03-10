import os
from time import time
from datetime import timedelta  
from lucene import *
       
class Searcher(object):  
      
    def search(self, indexDir, q):  
        fsDir = SimpleFSDirectory(File(indexDir))  
        searcher = IndexSearcher(fsDir, True)  
        query = QueryParser(Version.LUCENE_CURRENT, "contents",  
                            StandardAnalyzer(Version.LUCENE_CURRENT)).parse(q)  
        starttime = time()  
        hits = searcher.search(query, 50).scoreDocs  
        duration = timedelta(seconds=time() - starttime)  
          
        print "Found %d document(s) (in%s) that matched query '%s':" %(len(hits), duration, q)  
          
        for hit in hits:  
            doc = searcher.doc(hit.doc)  
            print 'path:', doc.get("path")  
   
def main():  
    initVM(CLASSPATH)  
    indexDir = "./index/"  
    q = "Killua"  
    searcher = Searcher()  
    searcher.search(indexDir, q)  
      
if __name__ == "__main__":  
    main()

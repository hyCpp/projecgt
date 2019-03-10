import os, sys
from time import time  
from datetime import timedelta  
from lucene import *  
from org.apache.lucene import *
from java.nio.file import Paths
from org.apache.lucene.analysis.miscellaneous import LimitTokenCountAnalyzer
from org.apache.lucene.analysis.standard import StandardAnalyzer
from org.apache.lucene.document import Document, Field, FieldType
from org.apache.lucene.index import \
    FieldInfo, IndexWriter, IndexWriterConfig, IndexOptions
from org.apache.lucene.store import SimpleFSDirectory

class Indexer(object):  
    _indexDir = ""  
    _dataDir = ""  
          
    def __init__(self, indexDir, dataDir):  
        self._indexDir = indexDir  
        self._dataDir = dataDir  
          
    def index(self):  
        if not (os.path.exists(self._dataDir) and os.path.isdir(self._dataDir)):  
            raise IOError, "%s isn't existed or is not a directory" % (self._dataDir)  
          
        dir = SimpleFSDirectory(Paths.get(self._indexDir))  
        writer = IndexWriter(dir, StandardAnalyzer(),  
                             True, IndexWriter.MaxFieldLength.LIMITED)  
        writer.setUseCompoundFile(False);  
        self.indexDirectory(writer, self._dataDir)  
        numIndexed = writer.numDocs();  
        writer.optimize()  
        writer.close()  
        dir.close()  
          
        return numIndexed  
      
    def indexDirectory(self, writer, dir):  
          
        for name in os.listdir(dir):  
            path = os.path.join(dir, name)  
            if os.path.isfile(path):  
                if path.endswith('.txt'):  
                    self.indexFile(writer, path)  
            elif os.path.isdir(path):  
                self.indexDirectory(writer, path)  
               
    def indexFile(self, writer, path):  
        try:  
            reader = InputStreamReader(FileInputStream(path), 'UTF-8')  
        except IOError, e:  
            print 'IOError while opening %s: %s' %(path, e)  
        else:  
            print 'Indexing', path  
            doc = Document()  
            doc.add(Field("contents", reader))  
            doc.add(Field("path", os.path.abspath(path),  
                          Field.Store.YES, Field.Index.NOT_ANALYZED))  
            writer.addDocument(doc)  
            reader.close()  
  	
def main():  
    initVM(CLASSPATH)
    if len(sys.argv) < 3:
    	sys.exit(1)
    indexDir = sys.argv[2]  
    dataDir = sys.argv[1]  
    indexer = Indexer(indexDir, dataDir)  
      
    start = time()  
    numIndexed = indexer.index()  
    duration = timedelta(seconds=time() - start)  
    print "Indexing %s files took %s" %(numIndexed, duration)  
      
if __name__ == "__main__":  
    main()

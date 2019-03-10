#encoding: utf-8

from lucene import *

texts=["Python是一个很有吸引力的语言", "C++语言也很有吸引力，长久不衰","我们希望Python和C++高手加入","我们的技术巨牛，人人都是高手"]

def search(searcher, qtext):
    tq = TermQuery(Term("content", qtext))
    hits = searcher.search(tq)
    print "----------------------------------------------"
    print "Query:'%s', %d Found" % (qtext,hits.length())
    for i in range(hits.length()):
        doc = hits.doc(i)
        print "\t",doc.get("content")

def dump(reader):
    for i in range(reader.maxDoc()):
	print "----------------------------------------------"
    tv = reader.getTermFreqVector(i, "content")
    for tk in tv.getTerms():
	print tk

initVM()
#directory = RAMDirectory()
#analyzer = PaodingAnalyzer()
writer = IndexWriter(directory, analyzer, True)
for text in texts:
    doc = Document()
    doc.add(Field("content", text, Field.Store.YES, Field.Index.TOKENIZED,
        Field.TermVector.YES))
    writer.addDocument(doc)
writer.optimize()
writer.close()
reader = IndexReader.open(directory)
dump(reader)
searcher = IndexSearcher(directory)
search(searcher, "python")
search(searcher, "C++")


TEMPLATE = subdirs
CONFIG += ordered

LIST = md5

for( item, LIST ) : exists( $$item ) : SUBDIRS += $$item

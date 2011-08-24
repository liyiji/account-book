
TEMPLATE = subdirs
CONFIG += ordered

LIST = accountBook

for( item, LIST ) : exists( $$item ) : SUBDIRS += $$item

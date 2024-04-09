import mechanize
def viewPage(url):
    browser=.Browser
    page=browser.open(url)
    source_code=page.read()
    print source_code
    viewPage('http://www.realitatea.net')
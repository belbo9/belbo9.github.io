source 'https://rubygems.org'

# Windows timezone support
platforms :mingw, :x64_mingw, :mswin, :jruby do
  gem "tzinfo", "~> 1.2"
  gem "tzinfo-data"
end

group :jekyll_plugins do
  gem 'wdm', '>= 0.1.0'
  gem 'jekyll'
  gem 'jekyll-feed'
  gem 'jekyll-sitemap'
  gem 'jekyll-redirect-from'
  gem 'jemoji'
  gem 'webrick', '~> 1.8'
  gem "bigdecimal"
end

# GitHub Pages compatibility (includes a specific Jekyll + plugins set)
gem 'github-pages'

# Fix for recent dependency requirements
gem 'connection_pool', '2.5.0'
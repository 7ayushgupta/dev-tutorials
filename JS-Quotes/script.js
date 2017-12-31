$(document).ready(function(){

	var quote,author;

	function getnewquote()
	{
		$.ajax({
			url: "http://api.forismatic.com/api/1.0/",
			jsonp:'jsonp',
			dataType:'jsonp',
			data: {
				method:'getQuote',
				format:'jsonp',
				lang:'en',
			},
			success: function(response){
				quote=response.quoteText;
				author=response.quoteAuthor;
				$('.quotetext').text(quote);
				if(!author)
				{
					author="Unknown";
				}
				$('.quoteauthor').text(' --' + author);
			}
		});
	}
	getnewquote();

	$('.newquote').on('click',function(event){
		event.preventDefault();
		getnewquote();
	});

	$('.btn-twitter').on('click',function tweet()
	{
		var tweetquote=quote+' --'+author;
		window.open("https://twitter.com/intent/tweet?text=" + tweetquote);
	});
});
